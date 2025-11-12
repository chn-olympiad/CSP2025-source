#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,gjr,c[20],f[20010],num;
long long ans=1LL<<60,cnt;
struct ll{
    int u,v,w;
};
vector<ll> e,e1;
vector<pair<int,int> > b[20];
inline bool lu(ll x,ll y){
    return x.w<y.w;
}
inline int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
inline void solve(){
    e1=e;
    num=n;
    cnt=0LL;
    for(int i=0;i<k;i++){
        if(((gjr>>i)&1)==1){
            num++;
            cnt+=1LL*c[i+1];
            for(pair<int,int> x:b[i+1])
                e1.push_back({num,x.first,x.second});
        }
    }
    for(int i=1;i<=num;i++)
        f[i]=i;
    sort(e1.begin(),e1.end(),lu);
    for(ll q:e1){
        int u=q.u,v=q.v,w=q.w;
        int x=find(u),y=find(v);
        if(x!=y){
            cnt+=1LL*w;
            f[x]=y;
        }
    }
    ans=min(ans,cnt);
    //printf("%lld %lld\n",cnt,gjr);
    /*for(auto x:e1){
        printf("%d %d %d\n",x.u,x.v,x.w);
    }*/
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //ohnonononono
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1,u,v,w;i<=n;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1,w;j<=n;j++){
            scanf("%lld",&w);
            b[i].push_back({j,w});
        }
    }
    while(gjr<(1<<(k))){
        solve();
        gjr++;
    }
    printf("%lld\n",ans);
    return 0;
}
