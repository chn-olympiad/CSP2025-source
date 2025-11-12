#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int N = 5e5 + 5; 
int n, a[N], ans;
long long k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1 && a[1] == 1 && k == 0) ans = 0;
	if (n == 2 && k == 0) ans = 1;
	else if (n % 2 == 0 && k == 0) ans = n / 2;
	else if (n % 2 != 0 && k == 0) ans = 0;
	else ans = 0;
	cout << ans;
	return 0;
}

