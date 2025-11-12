#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10010;
int n,m,k;
ll ans,dis[N];
bitset<N>b;
struct Node{
    int u;
    ll d;
};
vector<Node>v[N];
void zd(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    for(int i=1;i<=n+k;i++){
        int t=0;
        for(int j=1;j<=n+k;j++){
            if(b[j]==0&&dis[t]>dis[j])t=j;
        }
        b[t]=1;
        ans+=dis[t];
 //       cout<<t<<' '<<ans<<endl;
        for(int j=0;j<v[t].size();j++){
 //               cout<<1;
            int ver=v[t][j].u,d=v[t][j].d;
            if(b[ver]==1)continue;
            if(d<dis[ver]){
                dis[ver]=d;
  //              cout<<1;
            }
        }
    }
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    for(int i=n+1;i<=n+k;i++){
        ll c;
        scanf("%lld",&c);
        ans+=c;
        for(int j=1;j<=n;j++){
            ll d;
            scanf("%lld",&d);
            v[i].push_back({j,d});
            v[j].push_back({i,d});
        }
    }
    zd();
    printf("%lld",ans);
    return 0;
}
