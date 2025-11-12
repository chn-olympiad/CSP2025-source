#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAX=1e4+10;
struct node{
    int v,w;
    bool operator< (const node& n)const{
        return w>n.w;
    }
};
vector<node> mp[MAX];
int ans[MAX];
bool st[MAX];
bool use[MAX];
void dj(){
    priority_queue<node> pq;
    pq.push({1,0});
    while(pq.size()){
        node it=pq.top();
        pq.pop();
        if(st[it.v])continue;
        st[it.v]=1;
        for(auto i:mp[it.v]){
            //cout<<it.v<<"->"<<i.v<<endl;//
            if(ans[it.v]+i.w<ans[i.v]){
                ans[i.v]=ans[it.v]+i.w;
                pq.push({i.v,ans[it.v]+i.w});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=2;i<=n+k;i++){
        ans[i]=1e9;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int w;
        cin>>w;
        for(int j=1;j<=n;j++){
            cin>>w;
            mp[i+n].push_back({j,w});
            mp[j].push_back({i+n,w});
        }
    }
    dj();
    int out=-1;
    for(int i=1;i<=n+k;i++){
        //cout<<ans[i]<<" ";
        if(ans[i]>out&&ans[i]!=1e9){
            out=ans[i];
        }
    }
    cout<<out;
    return 0;
}