#include<cstdio>
#include<algorithm>
#include<set>
template<typename T>inline T read(void){
	T x = 0;
	char ch = std::getchar();
	bool f = true;
	while(ch<'0' || ch>'9'){
		if(ch == '-') f = false;
		ch = std::getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = std::getchar();
	}
	return f ? x : -x;
}
#define ll long long
const int M = 1e6+5,N = 1e4+5;
struct Graph{
	int u,v,w;
}G[M];
bool cmp(Graph a,Graph b){return a.w<b.w;}
int a[N][15],tmp[N][15],n,m,k;
struct Union_Find_Set{
	int Mn[N][10],fa[N];
	void init(int n){
		for(int i = 1;i<=n;++i){
			fa[i] = i;
			for(int j = 0;j<k;++j) Mn[i][j] = a[i][j];
		}
	}
	int Find(int u){
		if(u == fa[u]) return u;
		return fa[u] = Find(fa[u]);
	}
}UF;
std::set<int> B;
bool vis[15];
int C[15];
inline ll Get(void){
	ll Ans = 1e18;
	if(B.size() == 1) return 0;
	for(int S = 1;S<(1<<k);++S){
		ll now = 0;
		for(int i = 0;i<k;++i)
			if(S>>i&1) now += C[i];
		for(int i : B){
			int x = 1e9;
			for(int j = 0;j<k;++j)
				if(S>>j&1) x = std::min(x,UF.Mn[i][j]);
			now += x;
		}
		Ans = std::min(Ans,now);
	}
	/*for(int i = 0;i<k;++i){
		ll now = 0;
		for(int j : B) now += UF.Mn[j][i];
		Ans = std::min(Ans,now);
	}*/
	return Ans;
}
int main(){
	std::freopen("road.in","r",stdin);
	std::freopen("road.out","w",stdout);
	n = read<int>(),m = read<int>(),k = read<int>();
	for(int i = 1;i<=m;++i){
		G[i].u = read<int>();
		G[i].v = read<int>();
		G[i].w = read<int>();
	}
	std::sort(G+1,G+m+1,cmp);
	for(int j = 0;j<k;++j){
		C[j] = read<int>();
		for(int i = 1;i<=n;++i) tmp[j][i] = read<int>();
	}
	for(int j = 0;j<k;++j)
		for(int i = 1;i<=n;++i) a[i][j] = tmp[j][i];
	UF.init(n);
	for(int i = 1;i<=n;++i) B.insert(i);
	ll ans = 1e18,S = 0;
	ans = std::min(ans,Get());
	for(int i = 1;i<=m;++i){
		int rtU = UF.Find(G[i].u);
		int rtV = UF.Find(G[i].v);
		if(rtU == rtV) continue;
		for(int j = 0;j<k;++j) UF.Mn[rtU][j] = std::min(UF.Mn[rtU][j],UF.Mn[rtV][j]);
		UF.fa[rtV] = rtU;
		B.erase(rtV);
		S += G[i].w;
		ans = std::min(ans,S+Get());
	}
	printf("%lld",ans);
	//505585650
	//505585650
	return 0;
}

