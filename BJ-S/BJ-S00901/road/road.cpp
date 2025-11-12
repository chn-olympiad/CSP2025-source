#include <iostream>
#include<vector>
using namespace std;
int n,m,k,dp[10001][10001],vis[10001];
struct node{
    int next,value;
};
vector<int> q[10001];
int dfs(int x,int step){
    if(step==0)return 0;
    if(dp[x][step]>0)return dp[x][step];
    int minn=2e9;
    for(int i=0;i<q[x].size();i++){
        if(vis[q[x][i]]==1)continue;
        vis[q[x][i]]=1;
        minn=min(minn,dfs(q[x][i],step-1)+q[x][i].value);
        vis[q[x][i]]=0;
    }
    dp[x][step]=minn;
    return dp[x][step];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        q[u].push_back({v,w});
        q[v].push_back({u,w});
    }
    int c,a[10001];
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            int f[10001]={};
            f[j]=1;
            for(int p=0;p<q[j].size();p++){
                q[j][p].value=max(q[j][p].value,a[j]+a[q[j][p].next]+c);
                f[q[j][p].next]=1;
            }
            for(int p=1;p<=n;p++){
                if(f[p]!=1)q[j].push_back(a[j]+a[p]+c);
            }
        }
    }
    vis[1]=1;
    cout<<dfs(1,n-1);
    return 0;
}
