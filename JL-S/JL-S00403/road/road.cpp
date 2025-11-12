#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N][N];
int b[N];
bool
int n,m,k;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int v,u,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
        for(int j=1;j<=n;j++){
            cin>>a[m+i][j];
            a[j][m+i]=a[m+i][j];
        }
    }
    return 0;
}
