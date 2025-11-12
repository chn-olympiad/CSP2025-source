#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
    int c,q;
};
int n,m,k,dis[N],d,a[N],ans;
vector<node> v[M]; 
priority_queue<int,vector<int>,greater<int>> p;
bool vis[N];
void dijkstar(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    vis[1]=1;
    p.push(1);
    while(p.size()){
        int f=p.top();
        for(auto i:v[f]){
            int u=i.c;
            int w=i.q;
            if(dis[f]+w<dis[u]){
                dis[u]=dis[f]+w;
                if(!vis[u]){
                    p.push(u);
                    vis[u]=1;
                }
            }
        }p.pop();
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }dijkstar();
    for(int i=1;i<=k;i++){
        cin>>d>>a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            dis[i]=min(dis[i],a[1]+d+a[i]);
            ans+=dis[i];
        }
    }cout<<ans<<"\n";
    return 0;
}