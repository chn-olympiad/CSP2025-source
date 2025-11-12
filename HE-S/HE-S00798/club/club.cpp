#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5 ;

struct node {
	int a, b, c, chazhi;
} a[N];

bool cmpA(node a, node b) {
	return a.a > b.a;
}

bool cmpB(node a, node b) {
	return a.a - a.b > b.a - b.b;
}

bool cmpC(node a, node b) {
	return a.a - a.b - a.c > b.a  - b.b - b.c;
}
int n, ans, cnt;
bool flag;
void dfs(int now, int num1, int num2, int num3, int sum) {
	if (now > n) {
		if (num1 > n / 2 || num2 > n / 2 || num3 > n / 2) return ;
		else ans = max(ans, sum);
		cnt++;
		return ;
	}
	dfs(now + 1, num1 + 1, num2, num3, sum + a[now].a);
	dfs(now + 1, num1, num2 + 1, num3, sum + a[now].b);
	dfs(now + 1, num1, num2, num3 + 1, sum + a[now].c);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//cin.tie(0);ios::sync_with_stdio(0);
	
	srand(time(0));
	int T; cin >> T;
	while (T--) {
		ans = 0; cnt = 0; flag = 0;
		cin >> n;
		bool flagA = 1, flagB = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (!(a[i].b == 0 && a[i].c == 0)) flagA = 0;
			if (!a[i].c == 0) flagB = 0;
		}
		if (flagA) {
			int ans = 0;
			sort(a + 1, a + 1 + n, cmpA);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].a;
			}
			cout << ans << "\n";
		} else if (flagB) {
			int ans = 0;
			sort(a + 1, a + 1 + n, cmpB);
			for (int i = 1; i <= n; i++) {
				if (i <= n / 2) ans += a[i].a;
				else ans += a[i].b;
			}
			cout << ans << "\n";
		} else {
			sort(a + 1, a + 1 + n, cmpC);
			dfs(1, 0 ,0,0,0);
			cout << ans << "\n";
		}
		//sort(a + 1, a + 1 + n, cmp);
	}
	return 0;
}

