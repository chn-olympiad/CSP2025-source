#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int maxn=1e4+10,inf=1e17;
int N,n,m,k,c[maxn],a[11][maxn],fa[maxn],sz[maxn];
vector<pair<int,pair<int,int>>>g;
int ff(int x){
    if(fa[x]==x)return x;
    return fa[x]=ff(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back({w,{u,v}});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=N;j++){
            cin>>a[i][j];
            g.push_back({a[i][j],{N+i,j}});
        }
    }
    sort(g.begin(),g.end());
    n=N+k;
    int ans=inf;
    for(int s=0;s<(1<<k);s++){
        int cnt=0,rl=N;
        for(int i=0;i<k;i++){
            // cout<<((s>>i)&1);
            if((s>>i)&1){
                rl++;
                cnt+=c[i+1];
            }
        }
        for(int i=1;i<=n;i++)fa[i]=i;
        int tot=0;
        for(auto pr:g){
            // cout<<tot<<'\n';
            int w=pr.first,u=pr.second.first,v=pr.second.second;
            if(u>N&&((s>>(u-N-1)&1)==0))continue;
            int fu=ff(u),fv=ff(v);
            if(fu==fv){
                continue;
            }
            if(sz[fu]>sz[fv]){
                fa[fv]=fu;
                sz[fu]+=sz[fv];
            }
            else{
                fa[fu]=fv;
                sz[fv]+=sz[fu];
            }  
            cnt+=w;
            tot++;
            if(tot==rl-1)break;
        }
        // cout<<cnt<<'\n';
        ans=min(ans,cnt);
        // cout<<'\n'<<cnt<<":\n";
    }
    cout<<ans<<'\n';
}
//Ren5Jie4Di4Ling5%