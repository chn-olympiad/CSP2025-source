#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define SZ(x) ((x).size())
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define fi first
#define se second
#define pb push_back
#define F(x) ((x) % P)
#define FE(x) ((x) %= P)
using namespace std;
using ll = long long;
using db = double;
using PII = pair<int,int>;
using PLL = pair<ll,ll>;
using Edge = array<ll,3>;
constexpr ll infL = 1ll << 60;
constexpr int infI = 1 << 30;

const int N = 1e4 + 10;

const int K = 15;

// struct Edge{
// 	int u,v;
// 	ll w;
// 	//?
// 	bool operator < (const Edge &x) const {
// 		return w < x.w;
// 	}

// 	bool operator == (const Edge &x) const{
// 		return w == x.w && u == x.u && v == x.v;
// 	}
// };

int n,m,k;

int fa[N * 2];

ll c[K];

ll a[K][N];

set<array<ll,3>> e;

int find(int u){
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

ll ans = infL;

void dfs(int u,int num,ll add){
	if(u == k + 1){
		memset(fa,0,sizeof(fa));
		rep(i,1,num + 1) fa[i] = i;
		int cnt = 0;
		ll sum = 0;
		for(auto it = e.begin();it != e.end();it++){
			Edge _ = *it;
			int u = _[1],v = _[2];
			ll w = _[0];
			u = find(u),v = find(v);
			//if(add == 1) cerr << u << ' ' << v << ' ' << w << endl;
			if(u != v){
				cnt++;
				sum += w;
				//if(add == 1) cerr << w << endl;
				fa[u] = v;
			}
			//if(add == 1) cerr << "CT" << cnt << endl;
			if(cnt == num) break;
		}
		//cerr << sum + add << endl;
		ans = min(ans,sum + add);
		return ;
	}else{
		dfs(u + 1,num,add);
		set<array<ll,3>> tmp = e;
		rep(v,1,n) e.insert((Edge){a[u][v],num + 2,v});
		dfs(u + 1,num + 1,add + c[u]);
		e = tmp;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	vector<Edge> tmp;
	rep(i,1,m){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		tmp.pb({w,u,v});
	}
	sort(all(tmp));
	memset(fa,0,sizeof(fa));
	rep(i,1,n) fa[i] = i;
	int cnt = 0;
	ll tttt = 0;
	for(Edge _ : tmp){
		int u = _[1],v = _[2];
		ll w = _[0];
		//cerr << "W" << w << endl;
		u = find(u),v = find(v);
		if(u != v){
			cnt++;
			e.insert({w,u,v});
			fa[u] = v;
			tttt += w;
		}
		if(cnt == n - 1){
			break;
		}
	}
	//cerr << SZ(e) << endl;
	// cerr << tttt << endl;
	//for(Edge _ : e) cerr << _.u << ' ' << _.v << ' ' << _.w << endl;
	bool flag = 1;
	rep(i,1,k){
		scanf("%lld",&c[i]);
		if(c[i] != 0) flag = 0;
		rep(j,1,n){
			scanf("%lld",&a[i][j]);
			if(a[i][j] != 0) flag = 0;
		}
	}
	if(flag) return printf("0"),0;
	dfs(1,n - 1,0);
	printf("%lld",ans);
	return 0;
}