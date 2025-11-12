#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int K=15;
int n,m,k;
long long ans;
int a[K][N];
int vis[N],lst;
struct node{int v,w;};
vector<node> e[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
struct S{
    int l,r,wei;
    bool operator < (const S& other) const{
        return wei>other.wei;
    }
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e[x].push_back((node){y,z});
        e[y].push_back((node){x,z});
    }
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),cmp);
        //for(int j=0;j<e[i].size();j++) cout<<e[i][j].v<<" "<<e[i][j].w<<" ";
        //cout<<endl;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    //16/100: minimal generated tree, O(m)
    if(k==0){
        priority_queue<S> pq;
        pq.push({1,e[1][0].v,e[1][0].w});
        while(!pq.empty()){
            S now=pq.top();
            pq.pop();
            if(vis[now.l]==2||vis[now.r]==2) continue;
            ans+=now.wei;
            lst=now.wei;
            //cout<<now.l<<" "<<now.r<<" "<<now.wei<<endl;
            vis[now.l]++;
            vis[now.r]++;
            for(auto edge:e[now.l]){
                if(vis[edge.v]) continue;
                pq.push({now.l,edge.v,edge.w});
            }
            for(auto edge:e[now.r]){
                if(vis[edge.v]) continue;
                pq.push({now.r,edge.v,edge.w});
            }
        }
        cout<<ans-lst<<endl;
    }
    return 0;
}
