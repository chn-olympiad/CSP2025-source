#include <bits/stdc++.h>
#define int long long
#define INF 0x7fffffff
using namespace std;
const int N = 1e5 + 10, M = 998244353;
int n,m,ans = 1;
int c[N];

inline int read()
{
	char c; int x = 0, d = 1;
	for(;!isdigit(c);c=getchar()) if(c == '-') d = -1;
	for(;isdigit(c);c=getchar()) x = x * 10 + c - '0';
	return d * x;
}


signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = read(), m = read();
	string s; cin >> s;
	for(int i=1;i<=n;i++) c[i] = read();
	
	for(int i=n;i>=n-m;i--) ans = (ans * i) % M;
	for(int i=1;i<=m;i++) ans = (ans / i) % M; 
	
	printf("%lld", ans % M);
	
	return 0;
}
