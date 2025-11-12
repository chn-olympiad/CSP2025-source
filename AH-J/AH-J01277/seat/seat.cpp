#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> arr[i];
    }
    int R_sore = arr[1];
    sort (arr + 1, arr + 1 + n * m, greater<int>());
    int R_rank;
    for (int i = 1; i <= n * m; i++) {
		if (arr[i] == R_sore) {
			R_rank = i - 1;
		}
	}
    int ans_1 = R_rank / n + 1, ans_2 = R_rank % n + 1;
    if (ans_1 % 2 == 0) {
        ans_2 = n - ans_2 + 1;
    }
    cout << ans_1 << " " << ans_2;
    return 0;
}
