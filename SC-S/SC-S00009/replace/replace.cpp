#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inf 1e18
using namespace std;
const int maxn = 1e4 + 100;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) x = -x , putchar('-');
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int n , q;
string a[maxn] , b[maxn] , t1 , t2;
signed main() {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	n = read();
	q = read();
	for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	if(n >= 10000) {
		while(q--) writeh(0);
		return 0;
	}
	while(q--) {
		cin >> t1 >> t2;
		int l = 0 , r = t1.size() - 1 , len1 = r + 1;
		while(t1[l] == t2[l]) l++;
		while(t1[r] == t2[r]) r--;
		string h;
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int len = a[i].size();
			if(len < r - l + 1 || len > len1) continue;
			for(int j = max(0ll , r - len + 1); j <= min(l , len1 - len); ++j) {
				if(t1.substr(j , a[i].size()) != a[i]) continue;
				if(b[i] == t2.substr(j , a[i].size())) ans++;
			}
		}
		writeh(ans);
	}
	return 0;
}