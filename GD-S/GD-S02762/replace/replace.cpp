#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
struct node{
	string s1,s2;
}a[MAXN];
int n,q;
int read() {
	int ans = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1;c = getchar();}
	while (c >= '0' && c <= '9') {
		ans = ans*10+c-'0';
		c = getchar();
	}
	return ans*f;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	for (int i = 1; i <= q; i ++) {
		int ans = 0;
		string x,y;
		cin >> x >> y;
		for (int h = 1; h <= n; h ++ ) {
			if (x.find(a[h].s1) == y.find(a[h].s2)) ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}

