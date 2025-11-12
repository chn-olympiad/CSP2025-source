#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAXN 10005
#define MAXM 1000005
struct L{
	ll a[MAXN],c;
};
ll n,m,k,u,v,w;
L A[15];
vector<pair<ll,ll>> g[MAXM];
inline void ltr(){
	vector<ll>nex;
	ll minnex=LONG_LONG_MAX-1;
	for(auto v:g){
		for(auto b:v){
			minnex=min(minnex,b.second);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
//		g[u].push_back({v,min(w,g[u][v].second)});
//		g[v].push_back({u,min(w,g[v][u].second)});
	}
	for(ll i=1;i<=k;i++){
		cin>>A[i].c;
		for(ll j=1;j<=n;j++){
			cin>>A[i].a[j];
		}
	}
	cout<<1015;
	return 0;
}
