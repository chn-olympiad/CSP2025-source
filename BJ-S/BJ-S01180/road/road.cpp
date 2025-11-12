#include<bits/stdc++.h>
using namespace std;
struct node{
    long long v,w;
};
long long t,m,k,ans=INT_MAX,vis[10007],b[4003][4003],cz[4003];
vector<node> a[10007];
long long sum=0,r;
void dfs(long long n,long long fa,long long k){
    if(vis[n]==1) return;
    vis[n]=1;sum++;
    if(sum==t){
        ans=min(ans,k);
        vis[n]=0;
        sum--;
        return;
    }
    for(int i=0;i<a[n].size();i++){
        long long o=a[n][i].v;
        if(o==fa) continue;
        dfs(o,n,k+a[n][i].w);
    }
    sum--;
    vis[n]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t>>m>>r;
    memset(b,0x3f,sizeof(b));
    if(r==0){
        for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(node{v,w});
        a[v].push_back(node{u,w});
        }
        dfs(1,-1,0);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        b[u][v]=w;
        b[v][u]=w;
        }
    for(int i=1;i<=r;i++){
        int j;
        cin>>j;
        for(int p=1;p<=t;p++) cin>>cz[p];
        for(int p=1;p<t;p++){
            for(int q=p+1;q<=t;q++){
                b[p][q]=min(b[p][q],cz[p]+cz[q]);
            }
        }
    }
    for(int i=1;i<t;i++){
        for(int j=i+1;j<=t;j++){
            a[i].push_back(node{j,b[i][j]});
            a[j].push_back(node{i,b[i][j]});
        }
    }
    dfs(1,-1,0);
    cout<<ans;
    return 0;
}
