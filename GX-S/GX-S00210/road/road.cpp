#include<bits/stdc++.h>
#include<istream>
int n,m,k;
int a[100005][100005],c[100005][100005],b[100005][100005];
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int i1=1;i1<=3;i1++){
            cin>>a[i][i1];
        }
    }
    for(int j=1;j<=k;j++){
        for(int j1=1;j1<=n+1;j1++){
            cin>>b[j][j1];
        }
    }
    freopen("road.out","w",stdout);
    return 0;
}
