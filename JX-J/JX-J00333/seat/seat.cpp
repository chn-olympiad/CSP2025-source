#include <bits/stdc++.h>
using namespace std;
constexpr int N=15;
int n,m,xm,rk;
int scr[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int z=0;z<n*m;z++){
        cin>>scr[z];
    }
    xm=scr[0];
    sort(scr,scr+n*m,greater<int>());
    for (int z=0;z<n*m;z++){
        if (scr[z]==xm){rk=z;break;}
    }
    if ((rk/m)&1)cout<<rk/m+1<<' '<<n-rk%m;
    else cout<<rk/m+1<<' '<<rk%m+1;
    cout<<'\n';
    return 0;
}
