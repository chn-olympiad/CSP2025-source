#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005][3];
long long dfs(int ca, int cb, int cc, long long ma, long long mb, long long mc, int u, int n) {
	if (u == n) {
		return ma + mb + mc;
	}
	long long mx = 0; 
	if (ca < (n >> 1)) mx = max(mx, dfs(ca + 1, cb, cc, ma + a[u][0], mb, mc, u + 1, n));
	if (cb < (n >> 1)) mx = max(mx, dfs(ca, cb + 1, cc, ma, mb + a[u][1], mc, u + 1, n));
	if (cc < (n >> 1)) mx = max(mx, dfs(ca, cb, cc + 1, ma, mb, mc + a[u][2], u + 1, n));
	return mx;
}

struct mynode_1 {
	int a, b, c;
} a1[100005];
bool cmp_bya(const mynode_1 &a, const mynode_1 &b) {
	return a.a > b.a;
}
bool cmp_byb(const mynode_1 &a, const mynode_1 &b) {
	return a.b > b.b;
}
bool cmp_byc(const mynode_1 &a, const mynode_1 &b) {
	return a.c > b.c;
}
int solve1(int n) {
	for (int i = 0; i < n; i++) {
		cin >> a1[i].a >> a1[i].b >> a1[i].c;
	}
	int n2 = (n >> 1); 
	
	stable_sort(a1, a1 + n, cmp_bya);
	long long sum_a = 0;
	for (int i = 0; i < n2; i++) {
		sum_a += a1[i].a;
	}
	for (int i = n2; i < n; i++) {
		sum_a += max(a1[i].b, a1[i].c);
	}
	
	stable_sort(a1, a1 + n, cmp_byb);
	long long sum_b = 0;
	for (int i = 0; i < n2; i++) {
		sum_b += a1[i].b;
	}
	for (int i = n2; i < n; i++) {
		sum_b += max(a1[i].a, a1[i].c);
	}
	
	stable_sort(a1, a1 + n, cmp_byc);
	long long sum_c = 0;
	for (int i = 0; i < n2; i++) {
		sum_c += a1[i].c;
	}
	for (int i = n2; i < n; i++) {
		sum_c += max(a1[i].a, a1[i].b);
	}
	
	cout << max(sum_a, max(sum_b, sum_c)) << '\n'; 
	return 0;
}
int solve(int n) {
	
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	cout << dfs(0, 0, 0, 0, 0, 0, 0, n) << '\n';
	
	return 0;
}
int main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n > 15) {
			solve1(n);
		} else solve(n);
	}
	
	fclose(stdin);
	fclose(stdout);
} 
