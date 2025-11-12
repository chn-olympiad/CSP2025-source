#include<bits/stdc++.h>
using namespace std;
int n,m,k,g[10001][10001],v[10001],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u;
    for(int i=1;i<=m;i++){
        cin>>u>>w>>g[u][w];
        g[w][u]=g[u][w];
    }
    for(int i=1;i<=k;i++){
        cin>>u;
        for(int i=1;i<=n;i++){
            cin>>u;
            v[u]=1;
        }
    }
    long long minn;
    for(int i=1;i<=n;i++){
        if(v[i]==1) continue;
        minn=2000000000
        for(int j=1;j<=n;j++){
            if(v[j]==1){
                minn=min(minn,g[i][j]);
                ans+=g[i][j];
            }
        }
        v[i]=1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
