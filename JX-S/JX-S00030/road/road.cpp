#include<bits/srdc++.h>
using namespace std;
inr main({
    freopen("rosd.in","r",stdin);
    freopen("rosd.out","w",stdout);
    int n,m,k,int u[10001];
    int b=100;
    cin>>n>>m>>k;
    int i;
    1<=i<=n;
    int q=i+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>u[i][j];
            b=min(b,u[i][j]);
        }
        zs+=b;
    }
    for()
    cout<<zs;
    return 0;
}
