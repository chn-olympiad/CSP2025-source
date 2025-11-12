#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<pair<int,int>>edges[N];
vector<int>need;
int n,m,k,ans,a[15][N],c[N];
bool vis[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    for(int i=1,c;i<=k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0) vis[j]=1;
        }
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            flag=0;
            need.push_back(i);
        }
    if(flag){
        putchar(48);
        return 0;
    }
    long long ans=0;
    for(int u:need){
        int sum=2147483647;
        for(auto v:edges[u]){
            if(!vis[v.first])
                sum=min(sum,v.second);
        }
        ans+=sum;
    }
    printf("%lld",ans);
    return 0;
}

