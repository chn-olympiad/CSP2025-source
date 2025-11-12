#include<bits/stdc++.h>
using namespace std;
struct club{
    int c1,c2,c3,fs,sc,th;
    bool flag=0;
}a[200005];
struct pe{
    int hg,cnt=0;
}t[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int ts;
    cin>>ts;
    while(ts--){
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i].flag=0;
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            a[i].fs=max(a[i].c1,max(a[i].c2,a[i].c3));
            if(a[i].fs==a[i].c1&&a[i].flag==0){
                a[i].sc=max(a[i].c2,a[i].c3);
                a[i].th=min(a[i].c2,a[i].c3);
                if(t[1].cnt<=n/2){
                    t[1].cnt++;
                    t[1].hg+=a[i].fs;
                    a[i].flag=1;
                }
                else if(a[i].sc==a[i].c2&&a[i].flag==0){
                    if(t[2].cnt<=n/2){
                        t[2].cnt++;
                        t[2].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[3].cnt<=n/2){
                        t[3].cnt++;
                        t[3].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
                else if(a[i].sc==a[i].c3&&a[i].flag==0){
                    if(t[3].cnt<=n/2){
                        t[3].cnt++;
                        t[3].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[2].cnt<=n/2){
                        t[2].cnt++;
                        t[2].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
            }


            if(a[i].fs==a[i].c2&&a[i].flag==0){
                a[i].sc=max(a[i].c1,a[i].c3);
                a[i].th=min(a[i].c1,a[i].c3);
                if(t[2].cnt<=n/2){
                    t[2].cnt++;
                    t[2].hg+=a[i].fs;
                    a[i].flag=1;
                }
                else if(a[i].sc==a[i].c1&&a[i].flag==0){
                    if(t[1].cnt<=n/2){
                        t[1].cnt++;
                        t[1].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[3].cnt<=n/2){
                        t[3].cnt++;
                        t[3].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
                else if(a[i].sc==a[i].c3&&a[i].flag==0){
                    if(t[3].cnt<=n/2){
                        t[3].cnt++;
                        t[3].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[2].cnt<=n/2){
                        t[2].cnt++;
                        t[2].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
            }


            if(a[i].fs==a[i].c3&&a[i].flag==0){
                a[i].sc=max(a[i].c1,a[i].c2);
                a[i].th=min(a[i].c1,a[i].c2);
                if(t[3].cnt<=n/2){
                    t[3].cnt++;
                    t[3].hg+=a[i].fs;
                    a[i].flag=1;
                }
                else if(a[i].sc==a[i].c1&&a[i].flag==0){
                    if(t[1].cnt<=n/2){
                        t[1].cnt++;
                        t[1].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[2].cnt<=n/2){
                        t[2].cnt++;
                        t[2].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
                else if(a[i].sc==a[i].c2&&a[i].flag==0){
                    if(t[2].cnt<=n/2){
                        t[2].cnt++;
                        t[2].hg+=a[i].sc;
                        a[i].flag=1;
                    }
                    else if(a[i].flag==0&&t[1].cnt<=n/2){
                        t[1].cnt++;
                        t[1].hg+=a[i].th;
                        a[i].flag=1;
                    }
                }
            }
        }
        cout<<t[1].hg+t[2].hg+t[3].hg<<endl;
    }

    return 0;
}
