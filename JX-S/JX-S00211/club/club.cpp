#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int T, n;
struct node {
	int a, b, c;
} m[maxn];
bool cmp(node x, node y) {
	if(x.a == y.a) return x.b > y.b;
	else return x.a > y.a;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --) {
	    int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> m[i].a >> m[i].b >> m[i].c;
		sort(m + 1, m + n + 1, cmp);
		for(int i = 1; i <= n/2; i ++) ans += m[i].a;
		for(int i = n/2 + 1; i <= n; i ++) ans += m[i].b;
		cout << ans << "\n";
	}
	return 0;
}
