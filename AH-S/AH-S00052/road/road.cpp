#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
struct node{
    int to;ll w;
    bool operator<(const node &u)const{
        return w>u.w;
    }
};
int n,m,k,pt[N],cnt;
bool vis[N];
ll dis[N],ans;
vector<node>a[N];
ll prim(){
    priority_queue<node>q;
    q.push({1,0});
    dis[1]=0;
    while(!q.empty()){
        node u=q.top();
        q.pop();
        int i=u.to;
        if(vis[i])continue;
        if(i<=n){
            cnt++;
            ans+=u.w;
        }
        if(cnt==n)return ans;
        vis[i]=1;
        for(node v:a[i]){
            if(!vis[v.to]){
                q.push({v.to,v.w+pt[v.to]});
            }
        }
    }
    //for(int i=1;i<=n+k;i++)cout<<dis[i]<<' ';
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int u;
        cin>>u;
        pt[n+i]=u;
        for(int j=1;j<=n;j++){
            cin>>u;
            a[n+i].push_back({j,u});
            a[j].push_back({n+i,u});
        }
    }
    cout<<prim();
    return 0;
}
