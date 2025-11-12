#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105],c[15][15],n,m,cj,ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    cj=c[1][1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]>cj)ans++;
        }
    }
    cout<<ans/n+1<<' '<<ans%n+1;
    return 0;
    }
