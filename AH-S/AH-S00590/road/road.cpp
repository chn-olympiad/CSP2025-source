#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20;
const int M=15;
const int K=1e6+5;
const int FUCKCCF=2e5;
int a[N][N],r[M][N],dis[N][2],fw[K];
bool vis[N],t[M];
map<int,int>g;
struct node{
    int v,w,id;
};
vector<node>e[FUCKCCF];
int n,m,k,fk,ft,ans,per;
bool fa=1;
struct nodee{
    int u,d;
    bool operator<(const nodee &a)const{
        return a.d<d;
    }
};
void dijkstra(int st){
    fill(vis,vis+1+n,0);
    memset(dis,127,sizeof(dis));
    priority_queue<nodee>q;
    q.push(nodee{st,0});
    dis[st][0]=dis[st][1]=0;
    while(!q.empty()){
        nodee pu=q.top();
        int u=pu.u;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v,w=e[u][i].w;
            if(v>n&&!t[v-n]) continue;
            if(dis[v][0]>dis[u][0]+w){
                dis[v][0]=dis[u][0]+w;
                q.push(nodee{v,dis[v][0]});
            }
            if(dis[v][0]>dis[u][1]+w){
                dis[v][0]=dis[u][1]+w;
                g[e[u][v].id]++;
                q.push(nodee{v,dis[v][1]});
            }
            if(dis[v][1]>dis[u][1]+w){
                dis[v][1]=dis[u][1]+w;
                g[e[u][v].id]++;
                q.push(nodee{v,dis[v][1]});
            }
            else if(dis[v][1]>dis[u][0]+w){
                dis[v][1]=dis[u][0]+w;
                g[e[u][v].id]--;
                q.push(nodee{v,dis[v][0]});
            }
        }
    }
    return ;
}
int dij(int gz){
    int cnt=0;
    g.clear();
//    cout<<"CZ:";
    for(int i=1;i<=k;i++){
        if(!t[i]) continue;
        cnt+=r[i][0];
//        cout<<i<<" ";
    }
//    cout<<";DL:";
    n+=gz;
    for(int i=1;i<=n;i++) dijkstra(i);
    n-=gz;
    for(int i=1;i<=m;i++){
        if(!g[i]) continue;
        cnt+=fw[i];
//        cout<<i<<" ";
    }
//    cout<<";XL:";
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(!g[m+(i-1)*n+j]) continue;
            cnt+=r[i][j];
//            cout<<"("<<i<<" "<<j<<")"<<" ";
        }
    }
//    cout<<";ans=";
//    cout<<cnt<<endl;
    return cnt;
}
void dfs(int id,int gz){
    if(id==k+1){
        ans=min(ans,dij(gz));
        return ;
    }
    t[id]=1;
    dfs(id+1,gz);
    t[id]=0;
    dfs(id+1,gz+1);
    return ;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>fk>>ft>>fw[i];
        e[fk].push_back(node{ft,fw[i],i});
        e[ft].push_back(node{fk,fw[i],i});
        a[ft][fk]=a[fk][ft]=1;
        ans+=fw[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]) continue;
            a[i][j]=a[j][i]=2;
            e[i].push_back(node{j,0,0});
            e[j].push_back(node{i,0,0});
        }
    }
    for(int i=1;i<=k;i++){
        cin>>r[i][0];
        if(r[i][0]!=0) fa=0;
        for(int j=1;j<=n;j++){
            cin>>r[i][j];
            if(r[i][j]!=0) fa=0;
            e[n+(i-1)*n+j].push_back(node{j,r[i][j],m+(i-1)*n+j});
            e[j].push_back(node{n+(i-1)*n+j,r[i][j],m+(i-1)*n+j});
//            cout<<m+(i-1)*n+j<<" ";
            ans+=r[i][j];
        }
        ans+=r[i][0];
    }
    per=m+n*k;
    if(fa){
        for(int i=1;i<=k;i++) t[i]=1;
//        cout<<"K";
        cout<<dij(k);
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
