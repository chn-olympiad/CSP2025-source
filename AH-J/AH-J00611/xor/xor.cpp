/*
*/
#include<bits/stdc++.h>
#define N 1005
using namespace std;
struct list_num{
    int l,r;
}num[N*N];
int n,k;
int a[N];
bool vis[N*N];
bool t=false;
int f[N][N];
int mx=0;
vector<int> g[N*N];
void dfs(int x,int st,int step){
    if(x==st && step!=0){
        mx=max(mx,step);
        return ;
    }
    if(x!=st) vis[x]=true;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        if(!vis[u]) dfs(u,st,step+1);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) t=true;
        f[i][i]=a[i];
    }
    if(!t){
        //k=0
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int t=a[i];
        for(int j=i+1;j<=n;j++){
            t^=a[j];
            f[i][j]=t;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[i][j]==k){
                num[++cnt]={i,j};
            }
        }
    }
    int ans=min(1,cnt);
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(!(num[i].r>=num[j].l)){
                g[i].push_back(j),g[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(g[i].size()==0) continue;
        mx=0;
        for(int j=1;j<=cnt;j++) vis[j]=false;
        dfs(i,i,0);
        ans=max(ans,max(mx,2));
    }
    cout<<ans;
    return 0;
}
