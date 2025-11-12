#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+5, mod=998244353;
int n, m, c[N];
int cnt, p[N];
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;++i)	cin>>c[i];
	iota(p, p+n+1, 0);
	do {
		int res=0, _c=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='1' && _c<c[p[i]])	++res;
			else	++_c;
		cnt+=(res>=m);
	} while(next_permutation(p+1, p+n+1));
	cout<<cnt;
	return 0;
}

