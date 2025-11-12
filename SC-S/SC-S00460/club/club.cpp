#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+111;

struct Node {
	int id;
	long long num;
};

int t;
int n;
Node a[maxn], b[maxn], c[maxn];
bool v[maxn][3];
long long sum;
long long ans;

bool cmp(Node x, Node y) {
	return x.num > y.num;
}

void sum2(Node x[], Node y[], Node z[], int k) {
	sum = x[1].num;
	v[x[1].id][k] = 1;
	if (!v[y[1].id][k] && !v[z[1].id][k]) sum += max(y[1].num, z[1].num);
	else if (!v[y[1].id][k] && v[z[1].id][k]) sum += y[1].num;
	else if (v[y[1].id][k] && !v[z[1].id][k]) sum += z[1].num;
	else {
		sum += max(y[2].num, z[2].num);
	}
	ans = max(ans, sum);
}

void Sum(Node x[], Node y[], Node z[], int k) {
	sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n / 2; ++i) {
		sum += x[i].num;
		v[x[i].id][k] = 1;
	}
//	for(int i=1;i<=n;++i){
//		cout << v[i][k]<<" ";
//	}
//	cout<<"\n\n";
	int p = 1, q = 1;
	bool f1 = 0, f2 = 0;
	while (cnt < n / 2) {
		while (v[y[p].id][k] && p <= n) {
			++p;
		}
		while (v[z[q].id][k] && q <= n) {
			++q;
		}
//		cout << p << " " << q << "\n";

		if (p > n) f1 = 1;
		if (q > n) f2 = 1;
		if (f1) { //y数组没得选了
			sum += z[q].num;
			++q;
			++cnt;
		} else if (f2) {
			sum += y[p].num;
			++p;
			++cnt;
		} else {
			if (y[p].num > z[q].num) {
				v[y[p].id][k] = 1;
				sum += y[p].num;
				++p;
			} else if (y[p].num < z[q].num) {
				v[z[q].id][k] = 1;
				sum += z[q].num;
				++q;
			} else {
				long long h = 0;
				while (y[p].num == z[q].num && p <= n && q <= n) {
					h += y[p].num * 2;
					cnt += 2;
					if (cnt == n / 2 + 1) {
						h -= y[p].num;
						break;
					} else if (cnt == n / 2) {
						break;
					}
					++p;
					++q;
				}
				sum += h;
			}
		}

	}
//	cout << "\n" << sum << "\n";
	ans = max(ans, sum);
	sum = 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &a[i].num, &b[i].num, &c[i].num);
		a[i].id = i;
		b[i].id = i;
		c[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	sort(c + 1, c + n + 1, cmp);
	if (n == 2) {
		sum2(a, b, c, 1);
		sum2(b, a, c, 2);
		sum2(c, b, a, 3);
	} else {
		Sum(a, b, c, 1);
		Sum(b, a, c, 2);
		Sum(c, b, a, 3);
	}
	printf("%lld\n", ans);
	ans = 0;
	memset(v, 0, sizeof v);
}
//1
signed main() {
//	freopen("1.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		solve();
	}

	return 0;
}