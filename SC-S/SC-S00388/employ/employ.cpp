#include <bits/stdc++.h>
#if __linux__
#define ge getchar_unlocked
#define pu putchar_unlocked
#else
#define ge getchar
#define pu putchar
#endif
using namespace std;
typedef long long ll;
char ch;
template <typename T>
inline void read(T &x){
	x=0;bool sgn=0;
	while ('0'>ch||ch>'9') ch=ge(), sgn |= ch=='-';
	while ('0'<=ch&&ch<='9') x=x*10+ch-'0', ch=ge();
	if (sgn) x=-x;
}
template <typename T>
inline void write(T x){
	if (x<0) pu('-'), x=-x;
	static int sta[110], top = 0;
	do sta[top++] = x%10, x/=10; while (x);
	while (top) pu(sta[--top]+'0');
}
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
const int N = 504, U = 1<<18|7;
const ll mod = 998244353;
int n, m, a[N], len[U];
ll f[U][20], ans;
bool b[N], vis[U][20];
ll dfs(int s, int j){
//	fprintf(stderr, "s=%d j=%d\n", s, j);
	if (s==0&&j==0) return 1;
	if (j<0) return 0;
	if (len[s]<j) return 0;
	if (vis[s][j]) return f[s][j];
	vis[s][j] = 1;
	for (int i=0;i<n;++i){
		if (s>>i&1){
			if (!b[len[s]-1]) f[s][j] = (f[s][j] + dfs(s^(1<<i), j-1))%mod;
			else {
				if (j-1>=a[i]) f[s][j] = (f[s][j] + dfs(s^(1<<i), j-1))%mod;
				if (j<a[i]) f[s][j] = (f[s][j] + dfs(s^(1<<i), j))%mod;
			}
		}
	}
	return f[s][j];
}
int main(){
	fileio("employ");
	read(n), read(m);
	bool flag = 1;
	while (ch!='\n') ch=ge();
	for (int i=0;i<n;i++) b[i] = ge()-'0', flag &= b[i];
	for (int i=0;i<n;i++) read(a[i]);
	if (n<=18) {
		for (int i=1;i<(1<<n);++i) {
			len[i] = len[i&(i-1)]+1;
//			fprintf(stderr, "i=%d len[i]=%d\n", i, len[i]);
		} 
		for (int i=m;i<=n;++i){
			ans += dfs((1<<n)-1, n-i);
		}
		write(ans%mod);
	}
	else if (m==n&&flag){
		ans = 1;
		for (int i=1;i<=n;i++) ans = ans * i % mod;
		write(ans);
	}
	else pu('0');
	return 0;
}
