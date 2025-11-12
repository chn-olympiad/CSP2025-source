#include <cstdio>
#include <algorithm>
const int SZ = 1<<23;
char ch, buf[SZ], *p1, *p2;
#define ge() (p1==p2&&(p2=buf+fread(p1=buf, 1, SZ, stdin), p1==p2)?EOF:*p1++)
typedef long long ll;
template <typename T>
inline void read(T &x){
	x=0;while ('0'>ch||ch>'9') ch=ge();
	while ('0'<=ch&&ch<='9') x=x*10+ch-'0', ch=ge();
}
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
const int N = 1e4+20, M = 1e6+5;
int n, m, k, fa[N], cnt;
ll ans, c[12], tmp, x;
struct edge{
	int u, v;
	ll w;
	bool operator<(const edge&other){
		return w < other.w;
	}
}a[M], b[N*11];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline bool merge(int x, int y){
	x = find(x), y = find(y);
	if (x!=y) return fa[x] = y, 1;
	return 0;
}
#define check(x) (x<=n||i>>(x-n-1)&1)
int main(){
	fileio("road");
	read(n), read(m), read(k);
	for (int i=1;i<=m;i++)
		read(a[i].u), read(a[i].v), read(a[i].w);
	std::sort(a+1, a+1+m);
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=m;i++){
		if (merge(a[i].u, a[i].v)){
			ans += a[i].w;
			b[++cnt] = a[i];
			if (cnt==n-1) break;
		}
	}
	for (int i=0;i<k;++i){
		read(c[i]);
		for (int j=1;j<=n;++j){
			read(tmp);
			b[++cnt] = {n+i+1, j, tmp};
		}
	}
	std::sort(b+1, b+cnt+1);
	for (int i=0;i<(1<<k);++i){
		tmp = m = x = 0;
		for (int j=0;j<k;++j)
			if (i>>j&1)
				tmp += c[j], ++x;
		for (int j=1;j<=n+k;++j) fa[j] = j;
		for (int j=1;j<=cnt;++j){
			if (check(b[j].u)&&check(b[j].v)&&merge(b[j].u, b[j].v)){
				tmp += b[j].w;
				++m;
				if (m==n+x-1) break;
			}
		}
		if (tmp<ans) ans = tmp;
	}
	printf("%lld", ans);
	return 0;
}
