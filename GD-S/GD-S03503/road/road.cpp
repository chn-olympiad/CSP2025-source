#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k, c[110], fa[30010], a[110][10010];
vector<ll> g[20010];

struct T{
	ll u,v,w;
}l[2000100];

void init(){
	for(int i=1;i<=30000;++i){
		fa[i] = i;
	}
}

ll find(ll x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(ll x,ll y){
	x = find(x), y = find(y);
	fa[x] = y;
}

bool cmp(T x,T y){
	return x.w < y.w;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	init();
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
//			cin>>l[m+i].w;
//			l[m+i].u = j;
//			l[m+i].v = n+i;
			cin>>a[i][j];
		}
	}
	
//	ll cnt = 0;
//	for(int i=1;i<=k;++i){
//		for(int j=1;j<=n;++j){
//			for(int K=1;K<=n;++K){
//				++cnt;
//				l[m+cnt].u = j;
//				l[m+cnt].v = K;
//				l[m+cnt].w = a[i][j] + a[i][K];
//			}
//		}
//	}
//	m += cnt;
	
	sort(l+1,l+1+m,cmp);
	
	ll cnt = 0;
	ll ans = 0;
	for(int i=1;i<=m;++i){
		ll u = l[i].u, v = l[i].v, w = l[i].w;
		if(find(u) == find(v)) continue;
		if(u <= n && v <= n) cnt++;
		ans += w;
		merge(u,v);
		
		if(cnt == n-1) break;
	}
	cout<<ans;
	
	return 0;
}
