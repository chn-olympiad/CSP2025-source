#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	// xor: ^
	int n, k, cnt = 0;
	cin >> n >> k;
	vector<int> a(n), sfx(n+1);
	for (int i = 0; i < n; i++) cin >> a[i];
    sfx[0] = 0;
    for (int i = 0; i < n; i++) sfx[i+1] = sfx[i] ^ a[i];
    for (int l = 1; l < n+1; l++) {
        for (int r = l; r < n+1; r++) {
            if (abs(sfx[l] ^ sfx[r-1]) == k) {
                cnt++;
                l = r+1;
                break;
            }
        }
    }
    cout << cnt;

	return 0;
}
