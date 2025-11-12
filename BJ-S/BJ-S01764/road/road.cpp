#include<bits/stdc++.h>
using namespace std;
#define tiaoshi 0
int n,m,k;
int a[10005];
vector<long long> g[10005][2];
struct zt{
    int v;
    long long cost;
    inline bool operator < (const zt &b)const{
        return cost>b.cost;
    }
};
priority_queue<zt> q;
long long ans=0;
long long dn=0;
bool done[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    while(m--){
        long long u,v,w;
        cin>>u>>v>>w;
        g[u][0].push_back(v);
        g[u][1].push_back(w);
        g[v][0].push_back(u);
        g[v][1].push_back(w);
    }
    for(int i=1;i<=k;i++){
        cin>>a[0];
        int mid;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            if(a[j]==0)mid=j;
        }
        for(int j=1;j<=n;j++){
            if(j==mid)continue;
            g[mid][0].push_back(j);
            g[mid][1].push_back(a[j]);
            g[j][0].push_back(mid);
            g[j][1].push_back(a[j]);
        }
    }
    q.push((zt){1,0});
    while(!q.empty()){
        int x=q.top().v;
        long long d=q.top().cost;
        q.pop();
        if(done[x])continue;
        done[x]=1;
        ans+=d;
        if(++dn==n)break;
        for(int i=0;i<g[x][0].size();i++){
            q.push((zt){g[x][0][i],g[x][1][i]});
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define tiaoshi 0
int n,m,k;
vector<long long> g[10005][2];
long long costt[15];
struct edge{
    int v;
    long long w;file:

    inline bool operator < (const edge &b)const{
        return w<b.w;
    }
};
edge costw[15][10005];
long long costw2[15][10005];
vector<int> conta[15];
int minci[15];
int donen[15];
bool done[15][10015];
long long ans[15];
long long totcost[15];
struct zt{
    int t;
    int v;
    long long cost;
    inline bool operator < (const zt &b)const{
        return cost>b.cost;
    }
};
priority_queue<zt> q;
int main(){
    memset(totcost,39999,sizeof(totcost));
    memset(donen,0,sizeof(donen));
    memset(ans,0,sizeof(ans));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    while(m--){
        long long u,v,w;
        cin>>u>>v>>w;
        g[u][0].push_back(v);
        g[u][1].push_back(w);
        g[v][0].push_back(u);
        g[v][1].push_back(w);
    }
    for(int i=1;i<=k;i++){
        cin>>costt[i];
        for(int j=1;j<=n;j++){
            cin>>costw[i][j].w;
            costw2[i][j]=costw[i][j].w;
            costw[i][j].v=j;
        }
        sort(costw[i]+1,costw[i]+1+n);
        minci[i]=1;
    }
    q.push((zt){0,1,0});
    donen[0]=0;
    while(!q.empty()){
            if(tiaoshi){
        cout<<"k:   ";for(int i=0;i<=k;i++)cout<<i<<" ";cout<<endl;
        cout<<"don  ";for(int i=0;i<=k;i++)cout<<done[0][i+n]<<" ";cout<<endl;
        cout<<"dnn  ";for(int i=0;i<=k;i++)cout<<donen[i]<<" ";cout<<endl;
        cout<<"dis  ";for(int i=0;i<=k;i++)cout<<ans[i]<<" ";cout<<endl;
            }
        int t=q.top().t;
        int x=q.top().v;
        long long cost=q.top().cost;
        q.pop();
      if(tiaoshi)  cerr<<"start : "<<t<<" "<<x<<" "<<cost<<endl;
        if(x>n){
       if(tiaoshi)     if(done[0][x])continue;
   if(tiaoshi)         cerr<<t<<" "<<x<<" "<<cost<<endl;
            done[0][x]=1;
            int i=x-n;
            for(int j=1;j<=n;j++){
                done[i][j]=done[t][j];
       if(tiaoshi)         cout<<"upddone"<<j<<" "<<done[i][j]<<endl;
            }
            donen[i]=donen[t];
            ans[i]=ans[t]+cost;
            while(minci[i]<=n&&done[i][minci[i]])minci[i]++;
       if(tiaoshi)     cout<<"-#upd"<<costw[i][minci[i]].v<<" +"<<costw[i][minci[i]].w<<endl;
            q.push((zt){i,costw[i][minci[i]].v,costw[i][minci[i]].w});
            ans[i]=ans[i]+costt[i];
            conta[i]=conta[t];
            conta[i].push_back(t);
            continue;
        }
        if(done[t][x])continue;
  if(tiaoshi)      cerr<<t<<" "<<x<<" "<<cost<<endl;
        done[t][x]=1;
        donen[t]++;
        ans[t]+=cost;
        if(donen[t]==n){
            cout<<ans[t]<<endl;
            break;
        }
  if(tiaoshi)      cerr<<"upd0"<<endl;
        //updatet
        for(int i=1;i<=k;i++){
            bool updated=0;
            while(minci[i]<=n&&done[i][minci[i]])minci[i]++,updated=1;
            if(updated&&minci[i]<=n&&done[0][i+n]){
  if(tiaoshi)              cout<<"-0upd"<<i<<" "<<costw[i][minci[i]].v<<" +"<<costw[i][minci[i]].w<<endl;
                q.push((zt){i,costw[i][minci[i]].v,costw[i][minci[i]].w});
            }
        }
  if(tiaoshi)      cerr<<"upd1"<<endl;
        for(int i=1;i<=k;i++){
   if(tiaoshi)         cout<<"-1upd"<<i+n<<" +"<<costw2[i][x]<<endl;
            q.push((zt){t,i+n,costw2[i][x]});
        }
  if(tiaoshi)      cerr<<"upd2"<<endl;
        for(int i=0;i<g[x][0].size();i++){
            int v=g[x][0][i],w=g[x][1][i];
   if(tiaoshi)         cout<<"-2upd"<<v<<" +"<<w<<endl;
            q.push((zt){t,v,w});
        }
  if(tiaoshi)      cerr<<"res"<<endl;
        //respond
        for(int i=0;i<conta[t].size();i++){
            donen[conta[t][i]]=donen[t];
            done[conta[t][i]][x]=1;
            ans[conta[t][i]]=ans[t];
            int j=conta[t][i];
            if(j!=0&&minci[j]<=n){
   if(tiaoshi)         cout<<"-Rupd"<<costw[j][minci[j]].v<<" +"<<costw[j][minci[j]].w<<endl;
            q.push((zt){j,costw[j][minci[j]].v,costw[j][minci[j]].w});
            }
        }
    }
    return 0;
}

*/
