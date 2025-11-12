#include<iostream>
#include<queue>
using namespace std;
const int N=1e4+30;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > mp[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > tr;
int vis[N],mn[N],pay[N];
int fd[N];
int fdf(int nd){
    if(fd[nd]==nd)return nd;
    fd[nd]=fdf(fd[nd]);
    return fd[nd];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)fd[i]=i;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push({w,v});
        mp[v].push({w,u});
    }
    for(int i=1;i<=k;i++){
        cin>>mn[n+i];
        for(int j=1;j<=n;j++){
            int pay;
            cin>>pay;
            mp[n+i].push({mn[n+i]+pay,j});
            mp[j].push({mn[n+i]+pay,n+i});
        }
    }
    int lsttu=-114514,lsttv=-1919810;
    for(int i=1;i<=n+k;i++)tr.push({mp[i].top().first,i});
    while(!tr.empty()){
        int u=tr.top().second;
        int v=mp[u].top().second,w=tr.top().first;
        tr.pop();
        if(lsttu==u&&lsttv==v)break;
        lsttu=u,lsttv=v;
        mp[u].pop();
        if(mp[v].top().second==u)mp[v].pop();

        if(fdf(v)!=fdf(u)){//cout<<u<<" "<<v<<" "<<w<<endl;
            fd[v]=fd[u];
            ans+=w;
            if(v>n){
                vis[v]=mn[v];
            }
            else if(u>n){
                vis[u]=mn[u];
            }
        }
        if(!mp[v].empty())tr.push({mp[v].top().first-vis[v],v});
        if(!mp[u].empty())tr.push({mp[u].top().first-vis[u],u});
    }
    cout<<ans;
    return 0;
}
