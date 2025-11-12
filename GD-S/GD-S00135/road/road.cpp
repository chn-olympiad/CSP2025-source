#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int const maxn = 1e5+55;
int fa[maxn];
int n,m,k;

int find(int x){
	return fa[x] ^ x ? find(fa[x]) : x;
}
inline void meg(int x,int y){
	fa[find(x)] = find(y);
}

struct nod{
	int u,v;
	ll w;
};

vector<nod> e;
vector<nod> G;

int a[15][maxn];
int c[15];

inline void reset(){
	for(int i = 1; i <= n+k; ++i)  fa[i] = i;
}

int main(){
	ios:: sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; ++i){
		int u,v,w;
		cin>>u>>v>>w;
		G.push_back({u,v,w});	
	}
	for(int i = 1; i <= k; ++i){
		cin>>c[i];
		for(int j = 1; j <= n; ++j){
			cin>>a[i][j];
		}
	}
	ll ans = 0x7fffffff;
	for(int sta = 0; sta < (1ll<<k); ++sta){
		ll res = 0;
		reset();
		e = G;
		bool jianzhi = 0;
		for(int i = 1; i <= k; ++i){
			if(1ll<<(i-1) & sta and c[i] >= ans)  jianzhi = 1;
		}
		if(jianzhi)  continue ;
		for(int i = 1; i <= k; ++i){
			if((1ll<<(i-1)) & sta){
				res += c[i];
				for(int j = 1; j <= n; ++j){
					e.push_back({i+n,j,a[i][j]});
				}	
			}
		}
		sort(e.begin(),e.end(),[](nod aa,nod bb){
			return aa.w < bb.w;
		});
		for(auto y : e){
			if(find(y.u) ^ find(y.v)){
				res += y.w;
				meg(y.u,y.v);
			}
		}
		ans = min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}





















