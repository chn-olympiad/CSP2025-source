#include<bits/stdc++.h>
using namespace std;
int s[20][20];
int mt[120];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>mt[i];
    }int tt=mt[1],xb;
    sort(mt+1,mt+m*n+1);
    for(int i=1;i<=n*m;i++){
       if(mt[i]==tt)xb=i;
    }
    int f=1,j=1,p=1;
    //cout<<xb<<endl;
    for(int i=1;i<=n;i++){
        for(;j>=1&&j<=m;j+=f,p++){

               // cout<<j<<' '<<i<<' '<<p<<' '<< mt[p]<<endl;
            if(p==xb){
                cout<<j<<' '<<i;
                return 0;
            }
        }j-=f;
        f=-f;
    }
    return 0;
}
