#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    vector<pair<int,double>> e;
}a[100101];
struct edge{
    int v,w;
    bool operator<(const edge q)const{
        return w>q.w;
    }
};
bool vis[100101];
int cnt=0;
int sum,n;
//queue<edge> qq;
void scs(int st){
    priority_queue<edge> q;
    for(int i=0;i<a[st].e.size();i++){
        q.push({a[st].e[i].first,a[st].e[i].second});
    }
    vis[st]=1;
    while(!q.empty()){
        edge x=q.top();
        q.pop();
        //qq.push(x);
        if(vis[x.v]) continue;
        vis[x.v]=1;
        sum+=x.w;
        if(x.v>=1&&x.v<=n) cnt++;
        for(auto y:a[x.v].e){
            if(!vis[y.first]&&y.first!=x.v)q.push({y.first,y.second});
        }
        if(cnt==n) return;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].e.push_back({v,w});
        a[v].e.push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int cj;
        cin>>cj;
        for(int j=1;j<=n;j++){
            int aij;
            cin>>aij;
            a[j].e.push_back({i+n,aij+cj/2});
            a[i+n].e.push_back({j,aij+cj/2});
            //cout<<i+n<<" "<<j<<endl;
        }
    }
    scs(1);
    //while(!qq.empty()){
    //    cout<<qq.front().v<<" "<<qq.front().w<<"\n";
    //    qq.pop();
    //}
    cout<<sum;
}
