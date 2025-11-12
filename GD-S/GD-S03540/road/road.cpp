#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int,int>
#define fr first
#define sc second
typedef long long ll;
const int N = 1e4+100, M = 2e6+10;
int n,m,k,cnt,c[11],ar[11][N],num[N],top[11],fg[11],tot[11],tt,sk[N];
int fa[N];
int final[N],ec;
struct E{int u,v,w;} e[M],ne[M],stk[11][N];
bool check(){
	F(i,1,k) if (c[i]) return 0;
	return 1;
} 
int finds(int x){
	return fa[x]==x?x:fa[x]=finds(fa[x]);
}
void merge(int x,int y){
	int fx = finds(x), fy = finds(y);
	if (fx != fy) fa[fy] = fx;
}
bool cmp(E a,E b){
	return a.w < b.w;
}
inline ll kruskal(){
	F(i,1,n+k) fa[i] = i;
	sort(ne+1,ne+cnt+1,cmp);
	
	ll res = 0; int sum = 0;
	F(i,1,cnt){
		int u = ne[i].u, v = ne[i].v; ll w = ne[i].w;
		if (finds(u) == finds(v)) continue;
		merge(u,v);
		res += w;
		sum++;
		if (sum == n+k-1) break;
	}
	return res;
}
void solveA(){
	F(i,1,m) ne[++cnt] = e[i];
	F(i,1,k) F(j,1,n) ne[++cnt] = {i+n,j,ar[i][j]};
	cout << kruskal() << "\n"; 
}
void baoli(){
	ll ans = 1e18;
	F(S,0,(1<<k)-1){
		cnt = 0;
		F(i,1,m) ne[++cnt] = e[i];
		ll sum = 0;
		int tmp = S;
		F(i,1,k){
			num[i] = (tmp&1);
			tmp >>= 1;
		}
		F(i,1,k){
			if (num[i]){
				sum += c[i];
				F(j,1,n) ne[++cnt] = {i+n,j,ar[i][j]};
			}
		}
		
		ans = min(ans,kruskal()+sum);
	}
	cout << ans;
}
bool cmp2(E a,E b){
	return a.w > b.w;
}
ll ksk(){
	sort(e+1,e+m+1,cmp2);
	F(i,1,k) sort(&stk[i][1],&stk[i][top[i]+1],cmp2);
	
	F(i,1,n+k) fa[i] = i;
	ll res = 0; int sum = 0;
	while (1){
		ll w = (top[0]?e[top[0]].w:1e18); int op = 0;
		F(i,1,k){
			if (!top[i]) continue;
			ll s = stk[i][top[i]].w + (!fg[i]?c[i]:0);
			if (w > s) w = s, op = i; 
		}
		
		int u = (op==0?e[top[0]].u:stk[op][top[op]].u), v = (op==0?e[top[0]].v:stk[op][top[op]].v);
		top[op]--;
		if (finds(u) == finds(v)) continue;
		if (op && !fg[op]){fg[op] = 1; ++tt;}
		tot[op]++; sk[op] = w;
		merge(u,v);
		res += w;
		sum++;
		if (sum == n+k-1) break;
	}
	
	F(i,1,k){
		if (tot[i]==1){
			res -= sk[i];
		}
	}
	return res;
}
void work(){
	F(i,1,k) F(j,1,n) stk[i][++top[i]] = {i+n,j,ar[i][j]};
	top[0] = m;
	
	cout << ksk();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F(i,1,m){
		int u,v,w;
		cin >> u >> v >> w;
		e[i] = {u,v,w};
	}
	F(i,1,k){
		cin >> c[i];
		F(j,1,n) cin >> ar[i][j];
	}
	
	if (check() || !k){
		solveA();
	} else if (m <= 100000 && k <= 5){
		baoli();
	} else {
		work();
	}
	return 0;
} 
/*
问题在于我们求最小生成树时，不能把 [n+1,n+k] 的点的连通性考虑进去 
*/
