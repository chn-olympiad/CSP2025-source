#include<bits/stdc++.h>
using namespace std;
long long r[10001][10001],p[10001][10001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0,d[100001];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,n,p1;
        cin>>u>>n>>p1;
        r[u][n] = 1;
        r[n][u] = 1;
        p[u][n] = p1;
        p[u][n] = p1;
    }
    for(int i = 0;i<k;i++){
        int cr[10001];
        int c;cin>>c;
        for(int i=0;i<n;i++){
            cin>>cr[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(r[i][j]){
                r[i][j] = 0;
                r[i][j] = 0;
                ans+=p[i][j];
            }
        }
    }
    cout<<ans;
    return 0;
}
