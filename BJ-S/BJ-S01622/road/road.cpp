#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+10,maxn=2e4+10;
int n,m,k,lst=0,mx=-1,len=1;
long long sum,ans=900000000000000000;
bool vis[maxn*2];
vector<pair<int,int>> g[maxn],gt[maxn];
struct bian{
    long long u,v,pri;
}b[maxm],sss[maxm];
struct city{
    int pri,a[maxn];
}c[maxn];
bool cmp(bian x,bian y){
    return x.pri<y.pri;
}
void dfs(int u){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first,k=g[u][i].second;
        if(!vis[v]){
            if(v<=n) lst--;
            vis[v]=vis[u]=1;
            sum+=k;
            mx=max(mx,k);
            gt[u].push_back({v,k});
            gt[v].push_back({u,k});
            dfs(v);
        }
    }
}
void prim(int kkk){
    sum=0;
    lst=n-1;
    vis[1]=1;
    for(int i=1;i<=kkk;i++){
        int u=sss[i].u,v=sss[i].v,k=sss[i].pri;
        g[u].push_back({v,k});
        g[v].push_back({u,k});
        if(vis[u]) dfs(u);
        else if(vis[v]) dfs(v);
        if(lst<=0) break;
    }
    return;
}
void gogogo(int x,int pri){
    if(x==k+1){
        //cout<<pri<<endl;
        for(int i=1;i<=len;i++) sss[i]=b[i];
        sort(sss+1,sss+1+len,cmp);
        prim(len);
        /*
        for(int i=1;i<=len;i++) cout<<sss[i].pri<<' '; cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<":";
            for(int j=0;j<gt[i].size();j++){
                cout<<gt[i][j].first<<' ';
            }
            cout<<endl;
        }
        cout<<"*****"<<sum<<endl;
        cout<<len<<' '<<sum+pri<<endl;
        */
        ans=min(ans,sum+pri);
        return;
    }
    if(x==k) for(int i=1;i<=n;i++){
        vis[i]=0;
        g[i].clear();
        gt[i].clear();
    }
    gogogo(x+1,pri);
    for(int i=1;i<=n;i++){
        if(x==k){
            vis[i]=0;
            g[i].clear();
            gt[i].clear();
        }
        b[++len]={x+n,i,c[x].a[i]};
        b[++len]={i,x+n,c[x].a[i]};
    }
    gogogo(x+1,pri+c[x].pri);
    len-=n*2;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>b[i].u>>b[i].v>>b[i].pri;
    }
    len=m;
    for(int i=1;i<=k;i++){
        cin>>c[i].pri;
        for(int j=1;j<=n;j++){
            cin>>c[i].a[j];
        }
    }
    gogogo(1,0);
    cout<<ans<<endl;
    return 0;
}
