#include<bits/stdc++.h>
using namespace std;

int da,n,xie,daji=6,zhongji=12,fangyu=5,fei=3;


int main(){

    cout<<"   7        1 putong"<<endl;
    cout<<" 4   4      2 jingying"<<endl;
    cout<<"1 2 3 5     3 shangren"<<endl;
    cout<<"5 4 4 1     4 gouhuo"<<endl;
    cout<<"2 3 5 5     5 wenhao"<<endl;
    cout<<"6 6 6 6     6 baoxiang"<<endl;
    cout<<"4 2 1 1     7 boss"<<endl;
    cout<<"1 1 5 4"<<endl;
    cout<<"3 1 1 5"<<endl;
    cout<<"1 1 1 1"<<endl;
    cin>>da;
    if(da==1){
        n=54;
        xie=80;
        fei=3;
        cout<<"xie:"<<xie<<" daji daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
        while(n!=0||da!=11||xie!=0){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
            }
            if(da==3&&fei>1){
                n-=zhongji;
                fei-=2;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<"yishi"<<endl;
            }
            if(da==11){
                cout<<"round 1 over"<<endl;
                break;
            }
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
        while(n!=0||da!=11||xie!=0){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
            }
            if(da==3&&fei!=0){
                n-=daji;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-4<<endl;
            }
            if(da==11){
                cout<<"round 2 over"<<endl;
                break;
            }
        }
        xie-=4;
        if(xie>80){
            xie=80;
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
        while(1){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(n==0){
                cout<<"victory"<<endl;
                break;
            }
            if(xie==0){
                cout<<"game over"<<endl;
                break;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
            }
            if(da==3&&fei>1){
                n-=zhongji;
                fei-=2;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-7<<endl;
            }
            if(da==11){
                cout<<"round 3 over"<<endl;
                break;
            }
        }
        xie-=7;
        if(xie>80){
            xie=80;
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
        while(1){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }

            if(xie==0){
                cout<<"game over"<<endl;
                break;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
            }
            if(da==3&&fei!=0){
                n-=daji;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-10<<endl;
            }
            if(n==0){
                cout<<"victory"<<endl;
                break;
            }
            if(da==11){
                cout<<"round 4 over"<<endl;
                break;
            }
        }

    }
    if(da==2){
        n=48;
        xie=80;
        fei=3;
        cout<<"xie:"<<xie<<" daji daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
        while(n!=0||da!=11||xie!=0){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
            }
            if(da==3&&fei>1){
                n-=zhongji;
                fei-=2;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-11<<endl;
            }
            if(da==11){
                cout<<"round 1 over"<<endl;
                break;
            }
        }
        xie-=11;
        if(xie>80){
            xie=80;
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
        while(n!=0||da!=11||xie!=0){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
            }
            if(da==3&&fei!=0){
                n-=daji;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<"qianghua"<<endl;
            }
            if(da==11){
                cout<<"round 2 over"<<endl;
                break;
            }
        }
        if(xie>80){
            xie=80;
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
        while(1){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }
            if(n==0){
                cout<<"victory"<<endl;
                break;
            }
            if(xie==0){
                cout<<"game over"<<endl;
                break;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
            }
            if(da==3&&fei>1){
                n-=zhongji;
                fei-=2;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-7+6<<endl;
            }
            if(da==11){
                cout<<"round 3 over"<<endl;
                break;
            }
        }
        xie-=7;
        n+=6;
        if(xie>80){
            xie=80;
        }
        fei=3;
        cout<<"xie:"<<xie<<" daji daji daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
        while(1){
            cin>>da;
            if(fei==0&&da!=11){
                cout<<"meiqian"<<endl;
            }

            if(xie==0){
                cout<<"game over"<<endl;
                break;
            }
            if(da==1&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
            }
            if(da==2&&fei!=0){
                n-=daji;
                fei--;
                cout<<"xie:"<<xie<<" daji zhongji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
            }
            if(da==3&&fei!=0){
                n-=daji;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
            }
            if(da==4&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
            }
            if(da==5&&fei!=0){
                xie+=fangyu;
                fei-=1;
                cout<<"xie:"<<xie<<" daji fangyu "<<fei<<"  "<<"xie:"<<n<<-14<<endl;
            }
            if(n==0){
                cout<<"victory"<<endl;
                break;
            }
            if(da==11){
                cout<<"round 4 over"<<endl;
                break;
            }
        }

    }









    return 0;
}


