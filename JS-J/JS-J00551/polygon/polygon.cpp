#include <bits/stdc++.h>
#define MOD 988244353
using namespace std;

int n, arr[5005];
int maxn = 0, minn = INT_MAX;
int ans = 0;

void dfs(const int& dep = 1, const int& sum = 0, const int& maxn = 0, const int& cnt = 0) {
	if (dep > n) {
		if (sum > maxn * 2 and cnt >= 3) {
			ans++;
			ans %= MOD;
		}
	} else {
		dfs(dep + 1, sum, maxn, cnt);
		dfs(dep + 1, sum + arr[dep], max(maxn, arr[dep]), cnt + 1);
	}
}

void count() {
	unsigned long long nowa = n * (n - 1);
	unsigned long long nowb = 1 * 2;
	for (int i = 3; i <= n; i++) {
		nowa *= (n - i + 1);
		nowb *= i;
		ans = (ans + (nowa / nowb)) % MOD;
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n < 3) {
        cout << 0 << '\n';
        return 0;
    }
	for (int i = 1; i <= n; i++) {
        cin >> arr[i];
		maxn = max(maxn, arr[i]);
		minn = min(minn, arr[i]);
    }
	if (n <= 20) {
		dfs();
		cout << ans << '\n';
	} else if (minn == maxn) {
		count();
		cout << ans << '\n';
	}
	return 0;
}
