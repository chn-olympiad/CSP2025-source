#include<bits/stdc++.h>
using namespace std;
int t, n;
int a[100001][4];
long long solve(const int& i, long long value = 0) {
	if (i >= n) {
		return 0;
	}
	static int num[4] = {};
	for (int j = 1; j <= 3; j++) {
		if (num[j] < n / 2) {
			++num[j];
			value = max(value, solve(i + 1, value + a[i][j]));
			--num[j];
		}
	}
	return value;
}
bool F = true;
void f() {
	int *b = new int[n + 1]();
	for (int i = 1; i <= n; i++) {
		b[i] = a[i][1];
	}
	sort(b + 1, b + n + 1, 
	[](const int& A, const int& B) 
	-> bool {return A > B;});
	long long sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		sum += b[i];
	}
	delete[] b;
	b = NULL;
	printf("%lld\n", sum);
}
int main() {
    freopen("club.in", "r", std::in);
    freopen("club.out", "w", std::out);
	scanf("%d", &t);
	for (; t; --t) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] || a[i][3]) {
				F = false;
			}
		}
		if (F) {
			f();
			continue;
		}
		printf("%lld\n", solve(1));
	}
    return 0;
}
