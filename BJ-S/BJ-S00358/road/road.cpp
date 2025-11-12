#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct way{
    int now,to,val;
    bool operator<(const way& o) const{
        return o.val<val;
    }
};
int c[15];
int a[15][10004];
bool flag=1;
int fa[10004];
long long ans=0,res=0;
long long last=0;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
priority_queue<way> pq,biao;
bool vis[10004];
int sum=0;
void kurskar(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    while(sum!=n-1&&!biao.empty()){
        auto x=biao.top();
        // cout<<x.now<<' '<<x.to<<' '<<x.val<<endl;
        biao.pop();
        if(find(x.now)!=find(x.to)){
            // cout<<x.now<<' '<<x.to<<' '<<x.val<<endl;
            ans+=x.val;
            fa[find(x.now)]=x.to;
            sum++;
        }
    }
}
void boom(){
    exit(0);
}
int main(){
    // cout<<1<<endl;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    vector<vector<way>> vec(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // vec[u].push_back({v,w});
        // vec[v].push_back({u,w});
        pq.push({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int u,w;
        
        if(c[i]==0){
            for(int j=1;j<=n;j++){
                cin>>w;
                // cout<<i<<" "<<j<<" "<<w<<endl;
                // a[i][j]=w;
                pq.push({i,u,w});
            }

        }
        else{
            for(int j=1;j<=n;j++){
                cin>>w;
                // cout<<i<<" "<<j<<" "<<w<<endl;
                a[i][j]=w;
            }
        }
    }
    // boom();
    biao=pq;
    while(sum!=n-1&&!biao.empty()){
        auto x=biao.top();
        // cout<<x.now<<' '<<x.to<<' '<<x.val<<endl;
        biao.pop();
        if(find(x.now)!=find(x.to)){
            // cout<<x.now<<' '<<x.to<<' '<<x.val<<endl;
            ans+=x.val;
            fa[find(x.now)]=x.to;
            sum++;
        }
    }
    res=ans;
    // cout<<res<<' ';
    for(int i=1;i<=k;i++){
        if(c[i]>=res) continue;
        if(c[i]==0) continue;
        sum=0;
        ans=last;
        biao=pq;
        for(int j=1;j<=n;j++){
            biao.push({i,j,a[i][j]+c[i]});

        }
        ans+=c[i];
        kurskar();
        // cout<<'%'<<ans<<endl;
        if(res>ans){
            for(int j=1;j<=n;j++){
                pq.push({i,j,a[i][j]+c[i]});

            }
            last+=c[i];
            res=ans;
        }
    }
    // cout<<endl;
    cout<<res<<endl;
    // cout<<ans<<endl;
    return 0;



}