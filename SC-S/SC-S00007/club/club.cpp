#include<bits/stdc++.h>
using namespace std;
int n, T, ans,cnt=0;
struct St {
	int a, b, c;
} yuan[100005];
void dfs(int x, int as, int bs, int cs, int ass, int bss, int css) {
	cnt++;
	if(cnt>65000000){
		return;
	}
	if (x == n + 1) {
		ans = max((ass + bss + css), ans);
		return;
	}
	if ((cs + 1) <= (n / 2))
		dfs(x + 1, as, bs, cs + 1, ass, bss, css + yuan[x].c);
	if ((bs + 1) <= (n / 2))
		dfs(x + 1, as, bs + 1, cs, ass, bss + yuan[x].b, css);
	if ((as + 1) <= (n / 2))
		dfs(x + 1, as + 1, bs, cs, ass + yuan[x].a, bss, css);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		cnt=0;
		cin >> n;
		ans = 0;
		memset(yuan, 0, sizeof yuan);
		for (int i = 1; i <= n; i++) {
			cin >> yuan[i].a >> yuan[i].b >> yuan[i].c;
		}
		dfs(1, 0, 0, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}