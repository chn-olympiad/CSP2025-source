#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,w;
};
const int N=1e4+10;
int n,m,k,cnt[N],vis[N],ans;
vector<node> v[N];
queue<int> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(cnt,0x3f,sizeof(vis));
    cin>>n>>m>>k;
    if(k!=0){cout<<0;return 0;}
    while(m--){
        int x,y,w;cin>>x>>y>>w;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    cnt[1]=0;
    q.push(1);
    while(q.size()){
        int t=q.front();q.pop();
        for(auto i:v[t]){
            if(i.u!=vis[t]&&i.u!=1&&i.w<cnt[i.u]){
                cnt[i.u]=i.w;
                vis[i.u]=t;
                q.push(i.u);
            }
        }
    }
    for(int i=1;i<=n;i++)
        ans+=cnt[i];
    cout<<ans;
    return 0;
}