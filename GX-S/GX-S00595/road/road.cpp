#include <bits/stdc++.h>
using namespace std;
int n,m,k,w,u,v,rd[10010][10010],ans=0,c[10010],j[10010],jud[10010][10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=10009;i++){
        for(int j=1;j<=10009;j++){
            rd[i][j]=1e7;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        if(u>=v) swap(u,v);
        rd[u][v]=min(rd[u][v],w);
        jud[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(jud[i][j]){
                ans+=rd[i][j];
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
