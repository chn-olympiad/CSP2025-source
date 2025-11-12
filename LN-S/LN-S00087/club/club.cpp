#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, n;

struct node {
	int b[4];
} a[100005];

bool cmp(node a, node b) {
	return a.b[1] > b.b[1];
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%lld", &a[i].b[j]);
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		int cnt = 0;
		for (int i = 1; i <= n / 2; i++) {
			cnt += a[i].b[1];
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, n;
struct node {
	int b[4];
} a[100005];

bool cmp(node x, node y) {
	return max(x.b[1], x.b[2]) > max(y.b[1], y.b[2]);
}

int main() {
	// freopen("club.in", "r", stdin);
	// freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%lld", &a[i].b[j]);
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		int cnt = 0;
		if (n % 2 == 0) {
			for (int i = 1; i <= n / 2; i++) {
				cnt += ;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				cnt += a[i].b[2];
		}
		
}*/
