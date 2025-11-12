#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 5005;

int n, ans = 0;
int a[max_n];
int s[max_n];

int f(int x, int y) {
	int res = 1;
	for (int i = x; i >= y; i--)
		res *= i;
	
	for (int i = 1; i <= x - y; i++)
		res /= i;
		
	return res;
}

signed main() {	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n);
	
	bool flag = true;
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] != 1)
			flag = false;
	}
	
	if (flag)
		ans = (n - 1) * (n - 2) / 2;
	else {
		for (int i = 1; i <= (1 << n) - 1; i++) {
			int sum = 0, maxx = 0;
			
			for (int j = 0; j <= 20; j++)
				if ((i >> j) & 1)
					sum += a[j + 1], maxx = max(a[j + 1], maxx);
			
			
			if (sum > maxx * 2)
				ans++;
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}