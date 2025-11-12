#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000005;
map<pair<ll,ll>,ll>mp;
ll p[N],w[N],n,m,k,c,cnt,ans;
struct Edge{
    ll u,v,w;
};
bool comp(const Edge&a,const Edge&b){
    return a.w<b.w;
}
vector<Edge>e;
void init(ll n){
    for(ll i=1;i<=n;++i)p[i]=i;
}
ll find(ll x){
    if(p[x]==x)return x;
    ll tmp=find(x);
    w[x]+=w[p[x]];
    return p[x]=tmp;
}
void unite(ll a,ll b,ll c){
    ll ra=find(a),rb=find(b);
    if(ra!=rb){
        p[ra]=rb;
        w[ra]=c+w[b]-w[a];
    }
}
ll kruskal(){
    cnt=0;
    sort(e.begin(),e.end(),comp);
	ll ra,rb;
	for(auto to:e){
	 ra=find(to.u),rb=find(to.v);
	 if(ra!=rb){
	     p[ra]=rb;
	     ans+=w[ra];
	 }
	 if(++cnt==n-1)break;
	}
	if(cnt==n-1)return ans;
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=m;++i)
        cin>>u>>v>>w,e.push_back(Edge{u,v,w});
    for(ll i=1;i<=k;++i){
        for(ll j=1;j<=n;++j)cin>>c;
    }
    cout<<kruskal();
    return 0;
}
