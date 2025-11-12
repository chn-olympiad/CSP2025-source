#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,dis[N],st[N];
vector<pair<int,int>> e[N];
void f(){
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(1);
    st[1]=1;
    dis[1]=0;
    while(q.size()){
        int u=q.front();
        q.pop();st[u]=0;
        for(auto t:e[u]){
            int v=t.first;
            int w=t.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!st[v]){
                    q.push(v);
                    st[v]=1;
                }
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1,t;i<=k;i++){
        cin>>t;
        for(int j=1,x;j<=n;j++){
            cin>>x;
            e[i+n].push_back({j,x+t});
            e[j].push_back({i+n,x+t});
        }
    }
    f();
    int ans=-1,res;
    for(int i=1;i<=n;i++){
        if(dis[i]>ans)ans=dis[i],res=i;
    }
    cout<<ans;
    return 0;
}