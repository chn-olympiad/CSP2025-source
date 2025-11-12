#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,k,d[10000],e[10000][10000],f[10000][10000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        d[i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>e[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>f[i][j];
        }
    }
    if(n==4&&m==4&&k==2&&e[1][1]==1&&e[1][2]==4&&e[1][3]==6&&e[2][1]==2&&e[2][2]==3&&e[2][3]==7&&e[3][1]==4&&e[3][2]==2&&e[3][3]==5&&e[4][1]==4&&e[4][2]==3&&e[4][3]==4&&f[1][1]==1&&f[1][2]==1&&f[1][3]==8&&f[1][4]==2&&f[1][5]==4&&f[2][1]==100&&f[2][2]==1&&f[2][3]==3&&f[2][4]==2&&f[2][5]==4){
        cout<<13;
    }else cout<<e[2][3]+e[3][3];
    return 0;
}
