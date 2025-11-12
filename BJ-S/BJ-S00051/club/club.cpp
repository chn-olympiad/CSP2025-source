#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
struct people {
    int a,b,c;
    char d,e,f;
} club[N];
bool cmp(people x,people y) {
    if(x.a!=y.a) return x.a>y.a;
    if(x.b!=y.b) return x.b>y.b;
    if(x.c!=y.c) return x.c>y.c;
}
void judge() {
    for(int i=1;i<=n;i++) {
        if(club[i].a>club[i].b) {
            club[i].d='a';
            if(club[i].a<club[i].c) {
                club[i].d='c';
                if(club[i].a>club[i].b) {
                    club[i].e='a';
                    club[i].f='b';
                }
                else {
                    club[i].e='b';
                    club[i].f='a';
                }
            }
            else {
                if(club[i].c>club[i].b) {
                    club[i].e='c';
                    club[i].f='b';
                }
                else {
                    club[i].e='b';
                    club[i].f='c';
                }
            }
        }
        if(club[i].a<club[i].b) {
            club[i].d='b';
            if(club[i].b<club[i].c) {
                club[i].d='c';
                if(club[i].a>club[i].b) {
                    club[i].e='a';
                    club[i].f='b';
                }
                else {
                    club[i].e='b';
                    club[i].f='a';
                }
            }
            else {
                if(club[i].c>club[i].a) {
                    club[i].e='c';
                    club[i].f='a';
                }
                else {
                    club[i].e='a';
                    club[i].f='c';
                }
            }
        }
    }
}
void find() {
    int cluba=0,clubb=0,clubc=0,num=0;
    for(int i=1;i<=n*2;i++) {
        if(club[i].d=='a') {
            if(cluba<n) {
                num+=club[i].a;
                cluba++;
            }
            else {
                if(club[i].e=='b') {
                    if(clubb<n) {
                        num+=club[i].b;
                        clubb++;
                    }
                    else {
                        num+=club[i].c;
                        clubc++;
                    }
                }
                else {
                    if(clubc<n) {
                        num+=club[i].c;
                        clubc++;
                    }
                    else {
                        num+=club[i].b;
                        clubb++;
                    }
                }
            }
        }
        if(club[i].d=='b') {
            if(clubb<n) {
                num+=club[i].b;
                clubb++;
            }
            else {
                if(club[i].e=='c') {
                    if(clubc<n) {
                        num+=club[i].c;
                        clubc++;
                    }
                    else {
                        num+=club[i].a;
                        cluba++;
                    }
                }
                else {
                    if(cluba<n) {
                        num+=club[i].a;
                        cluba++;
                    }
                    else {
                        num+=club[i].c;
                        clubc++;
                    }
                }
            }
        }
        if(club[i].d=='c') {
            if(clubc<n) {
                num+=club[i].c;
                clubc++;
            }
            else {
                if(club[i].e=='a') {
                    if(cluba<n) {
                        num+=club[i].a;
                        cluba++;
                    }
                    else {
                        num+=club[i].b;
                        clubb++;
                    }
                }
                else {
                    if(clubb<n) {
                        num+=club[i].b;
                        clubb++;
                    }
                    else {
                        num+=club[i].a;
                        cluba++;
                    }
                }
            }
        }
    }
    cout<<num<<endl;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>club[i].a>>club[i].b>>club[i].c;
        judge();
        sort(club+1,club+1+n,cmp);
        n/=2;
        find();
    }
    return 0;
}
