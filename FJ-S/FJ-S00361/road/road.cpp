#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define F(i,a,b) for( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define emb(x) emplace_back(x) 
const int MAXN =2e4+5,MAXM =3e6+5;
using ll =long long;

using namespace std;
struct Node{
	int to,w;
};
struct Edge{
	int u,v,w;
}e[MAXM];
vector<Node> g[MAXN];
int n,m,k,fa[MAXN],val[MAXN],c[15],a[15][MAXN];
int tot;
ll ans;

int find( int x) {
	return x ==fa[x]? x:fa[x] =find(fa[x]); 
}

void kruskal( int p) {
	sort(e+1,e+tot+1,[](Edge x,Edge y) {
		return x.w <y.w;
	});
	int cnt =0;
	F ( i,1,tot) {
		int u =e[i].u,v =e[i].v,w =e[i].w;
		int fu =find(u),fv =find(v);
		if ( fu !=fv) {
			fa[fu] =fv;
			++cnt,ans +=e[i].w;
			if ( cnt ==p-1) break;
		}
	}
	cout <<ans <<'\n';
}

void solve() {
	cin >>n >>m >>k; 
	ans =0;
	F ( i,1,n+1) fa[i] =i;
	F ( i,1,m) {
		int u,v,w; cin >>u >>v >>w;
		g[u].push_back({v,w}),g[v].push_back({u,w});
		e[++tot] ={u,v,w};
	} 
	F ( i,1,k) {
		cin >>c[i];
		F ( j,1,n) cin >>a[i][j];
	}
	if ( !k) kruskal(n);
	else {
		F ( i,1,k) {
			F ( j,1,n) {
				e[++tot] ={n+1,j,a[i][j]}; 				
			}
		}
		kruskal(n+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	
	solve();
	
	return 0;
}
/****

4 5 0
1 2 2
2 3 2
1 4 3
3 4 2
1 3 1

****/
