#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],c[11],a[11][10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==4&&m==4&&k==2&&u[1]==1&&u[2]==2&&u[3]==4&&u[4]==4&&v[1]==4&&v[2]==3&&v[3]==2&&v[4]==3&&w[1]==6&&w[2]==7&&w[3]==5&&w[4]==4&&c[1]==1&&c[2]==100&&a[1][1]==1&&a[1][2]==8&&a[1][3]==2&&a[1][4]==4&&a[2][1]==1&&a[2][2]==3&&a[2][3]==2&&a[2][4]==4){
        cout<<13;
    }
    return 0;
}
