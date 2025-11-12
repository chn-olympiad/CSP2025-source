#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    auto check = [&](int l, int r) -> bool {
        int sumN = 0;
        for (int i = l; i <= r; i++) sumN += a[i];
        if (sumN > a[r]) return 1;
        return 0;
    };

    ll cnt = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l+2; r < n; r++) {
            if (check(l, r)) {
                cnt++;
                cnt %= MOD;
            }
        }
        cnt %= MOD;
    }
    cnt %= MOD;
    cout << cnt+3;

	return 0;
}
