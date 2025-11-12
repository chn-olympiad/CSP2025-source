#include <bits/stdc++.h> 
using namespace std;

const int N = 100010;
int n, a[N][4], mx[N], se[N], box[4];

void Main() {
	memset(box, 0, sizeof box);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			scanf("%d", &a[i][j]);
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			mx[i] = 1;
			if (a[i][2] >= a[i][3]) se[i] = 2;
			else se[i] = 3;
		} else if (a[i][2] >= a[i][3] && a[i][2] >= a[i][1]) {
			mx[i] = 2;
			if (a[i][1] >= a[i][3]) se[i] = 1;
			else se[i] = 3;
		} else {
			mx[i] = 3;
			if (a[i][1] >= a[i][2]) se[i] = 1;
			else se[i] = 2;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		box[mx[i]]++, ans += 1ll * a[i][mx[i]];
	int wr = -1;
	for (int i = 1; i <= 3; i++)
		if (box[i] > n / 2) {
			wr = i;
			break;
		}
	if (wr == -1) printf("%lld\n", ans);
	else {
		priority_queue<long long, vector<long long>, greater<long long> > q;
		for (int i = 1; i <= n; i++)
			if (mx[i] == wr)
				q.push(a[i][mx[i]] - a[i][se[i]]);
		while (q.size() > n / 2) {
			long long x = q.top(); q.pop();
			ans -= x;
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) Main();
	return 0;
}
