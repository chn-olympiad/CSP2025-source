#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
template <typename T> inline void read(T &x){
	x = 0;
	LL f = 1;
	char c = getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c=getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void print(T x){
	if(x < 0) x = -x,putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
inline void sprint(const string s){
	for(auto x : s) putchar(x);
	return;
}
const int N = 1e5 + 11,M = 20;
LL n,m,k;
struct edge{
	LL st,dst,val;
};
LL a[M],g[M][N];
bool fl[M];
vector<edge> v;
bool cmp(edge x,edge y){
	if(x.val < y.val) return 1;
	return 0;
}
struct DSU{
	vector<LL> par;
	DSU(LL n){
		par.resize(n + 1);
		for(LL i=1;i<=n;i++) par[i] = i;
	}
	LL find(LL u){
		if(par[u] != u) return par[u] = find(par[u]);
		else return u;
	}
	void comb(LL u,LL v){
		LL rtu = find(u),rtv = find(v);
		if(rtu == rtv) return;
		par[rtu] = rtv;
		return;
	}
	bool connected(LL u,LL v){
		if(find(u) == find(v)) return 1;
		return 0;
	}
	vector<LL> getcomp(LL u){
		vector<LL> comp;
		comp.clear();
		LL rtu = find(u);
		for(LL i=1;i<=n;i++){
			LL rt = find(i);
			if(rt == rtu) comp.emplace_back(i);
		}
		return comp;
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(LL i=1;i<=m;i++){
		LL st,dst,val;
		read(st);read(dst);read(val);
		v.emplace_back((edge){st,dst,val});
	}
	for(LL i=1;i<=k;i++){
		read(a[i]);
		for(LL j=1;j<=n;j++) read(g[i][j]);
	}
	sort(v.begin(),v.end(),cmp);
	DSU unit(n);
	LL tot = 0,pt = n,cnt = 0;
	for(auto x : v){
		if(unit.connected(x.st,x.dst) == 1) continue;
		vector<LL> comp1 = unit.getcomp(x.st);
		vector<LL> comp2 = unit.getcomp(x.dst);
		priority_queue<LL,vector<LL>,greater<LL>> pq1,pq2;
		LL ans = 1e18,pos = 0;
		for(LL i=1;i<=k;i++){
			LL tt = 0;
			if(fl[i] == 0) tt += a[i];
			while(pq1.size()) pq1.pop();
			while(pq2.size()) pq2.pop();
			for(auto u : comp1) pq1.push(g[i][u]);
			for(auto u : comp2) pq2.push(g[i][u]);
			tt += (pq1.top() + pq2.top());
			if(ans > tt){
				ans = tt;
				pos = i;
			}
		}
		if(ans <= x.val){
			tot += ans;
			fl[pos] = 1;
		}else tot += x.val;
		unit.comb(x.st,x.dst);
		cnt ++;
		if(cnt == pt - 1) break;
	}
	print(tot);
	return 0;
}