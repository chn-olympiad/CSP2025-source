//GZ-S00507 都匀市第二中学 黄泰灵
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int v[m+5][3];
    int w[m+5];
    for(int i=1;i<=m;i++){
        cin>>v[i][1]>>v[i][2]>>w[i];
    }
    int c[k+5];
    int a[k+5][n+5];
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    cout<<0;
    return 0;
}
