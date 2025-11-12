#include<bits/stdc++.h>
using namespace std;
struct node{
    long long v,mn;
    bool operator > (const node &x) const{
         return mn>x.mn;
    }
};
vector<node>t[10005];
long long n,m,k;
long long vis[10005];
long long ans=0;
void solve(){
    for(long long i=1;i<=m;i++){
        long long x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        t[x].push_back({y,z});
        t[y].push_back({x,z});
    }
    priority_queue<node,vector<node>,greater<node> >dq;
    long long cnt=1;
    vis[1]=1;
    for(auto tmp:t[1]){
        dq.push({tmp.v,tmp.mn});
    }
    while(cnt!=n){
        node tmp=dq.top();
        dq.pop();
        if(vis[tmp.v]){
            continue;
        }
        ans+=tmp.mn;
        for(auto u:t[tmp.v]){
            if(!vis[u.v])dq.push({u.v,u.mn});
        }
        cnt++;
    }
    cout<<ans;
}
long long l[15][10005];
void solve1(){
    for(long long i=1;i<=m;i++){
        long long x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        t[x].push_back({y,z});
        t[y].push_back({x,z});
    }
    for(long long i=1;i<=k;i++){
        long long __;
        scanf("%lld",&__);
        for(long long j=1;j<=n;j++){
            scanf("%lld",&l[i][j]);
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            long long minn=0x3f3f3f3f;
            for(long long o=1;o<=k;o++){
                minn=min(minn,l[o][i]+l[o][j]);
            }
            t[i].push_back({j,minn});
            t[j].push_back({i,minn});
        }
    }
    priority_queue<node,vector<node>,greater<node> >dq;
    long long cnt=1;
    vis[1]=1;
    for(auto tmp:t[1]){
        dq.push({tmp.v,tmp.mn});
    }
    while(cnt!=n){
        node tmp=dq.top();
        dq.pop();
        if(vis[tmp.v]){
            continue;
        }
        ans+=tmp.mn;
        for(auto u:t[tmp.v]){
            if(!vis[u.v])dq.push({u.v,u.mn});
        }
        cnt++;
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    if(k==0){
        solve();
        return 0;
    }
    solve1();
    return 0;
}
