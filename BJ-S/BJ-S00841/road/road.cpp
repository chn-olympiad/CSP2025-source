#include<bits/stdc++.h>
using namespace std;
const int N=1e4+14;
int n,m,k,cnt,a,c[11],u,v,w,vis[N],dis[N];
long long ans,sum;
struct T{
    int v,w;
    bool operator<(const T&b)const{
        return w>b.w;
    }
};
vector<T>g[N];
priority_queue<T>q;
void pm(int k,int b){
    while(!q.empty())q.pop();
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    cnt=0,dis[1]=0;
    q.push({1,0});
    while(q.size()){
        u=q.top().v,w=q.top().w;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        cnt++;
        sum+=w;
        if(sum>=ans)return;
        if(cnt==n+b){
            ans=sum;
            return;
        }
        for(auto x:g[u]){
            if(dis[x.v]<=x.w||vis[x.v]||(x.v>n&&((~k)&(1<<(x.v-n-1)))))continue;
            dis[x.v]=x.w;
            q.push(x);
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ans=9223372036854775807;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<k;++i){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a;
            g[j].push_back({i+n+1,a});
            g[i+n+1].push_back({j,a});
        }
    }
    for(int i=0;i<(1<<k);i++){
        cnt=sum=0;
        for(int j=k-1;~j;j--)
            if(i&(1<<j)){
                cnt++;
                sum+=c[j];
            }
        pm(i,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}