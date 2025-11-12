#include <bits/stdc++.h>
using namespace std;

int findmax(int arr[], int n) {
	int maxn = 0, maxid = 0;
	for (int i = 0; i < n; i++) {
		if (maxn > arr[i]) {
			maxn = arr[i];
			maxid = i;
		} 
	}
	return maxid;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		int arr[100000][3], club[100000], a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			if (arr[i][0] > arr[i][1]) {
				if (arr[i][0] > arr[i][2]) {
					club[i] = 0;
					a++;
				} else {
					club[i] = 2;
					c++;
				}
			} else {
				if (arr[i][1] > arr[i][2]) {
					club[i] = 1;
					b++;
				}
				else {
					club[i] = 2;
					c++;
				}
			}
			ans += arr[i][club[i]];
		}
		if (a > n / 2) {
			int j = 0;
			int brr[50000], crr[50000], max_diff = -1, max_diff_id = -1;
			for (int i = 0; i < n; i++) {
				if (club[i] == 0) {
					if (j < a - n / 2) {
						brr[j] = i;
						crr[j] = arr[i][0] - arr[i][1] > arr[i][0] - arr[i][2] ?
							arr[i][0] - arr[i][2] : arr[i][0] - arr[i][1];
						if (max_diff < crr[j]) {
							max_diff_id = j;
							max_diff = crr[j];
						}
						club[i] = arr[i][0] - arr[i][1] < arr[i][0] - arr[i][2] ? 1 : 2;
						j++;
					} else {
						if ((arr[i][0] - arr[i][1] > arr[i][0] - arr[i][2] ?
							arr[i][0] - arr[i][2] : arr[i][0] - arr[i][1]) < max_diff) {
							club[brr[max_diff_id]] = 0;
							brr[max_diff_id] = i;
							crr[max_diff_id] = arr[i][0] - arr[i][1] > arr[i][0] - arr[i][2] ?
							arr[i][0] - arr[i][2] : arr[i][0] - arr[i][1];
							max_diff_id = findmax(crr, a - n / 2);
							max_diff = crr[max_diff_id];
						}
					}
				}
			}
			for (int i = 0; i < a - n / 2; i++) ans -= crr[i];
		} else if (b > n / 2) {
			int j = 0;
			int brr[50000], crr[50000], max_diff = -1, max_diff_id = -1;
			for (int i = 0; i < n; i++) {
				if (club[i] == 1) {
					if (j < b - n / 2) {
						brr[j] = i;
						crr[j] = arr[i][1] - arr[i][0] > arr[i][1] - arr[i][2] ?
							arr[i][1] - arr[i][2] : arr[i][1] - arr[i][0];
						if (max_diff < crr[j]) {
							max_diff_id = j;
							max_diff = crr[j];
						}
						club[i] = arr[i][1] - arr[i][0] < arr[i][1] - arr[i][2] ? 0 : 2;
						j++;
					} else {
						if ((arr[i][1] - arr[i][0] > arr[i][1] - arr[i][2] ?
							arr[i][1] - arr[i][2] : arr[i][1] - arr[i][0]) < max_diff) {
							club[brr[max_diff_id]] = 1;
							brr[max_diff_id] = i;
							crr[max_diff_id] = arr[i][1] - arr[i][0] > arr[i][1] - arr[i][2] ?
							arr[i][1] - arr[i][2] : arr[i][1] - arr[i][0];
							max_diff_id = findmax(crr, b - n / 2);
							max_diff = crr[max_diff_id];
						}
					}
				}
			}
			for (int i = 0; i < b - n / 2; i++) ans -= crr[i];
		} else if (c > n / 2) {
			int j = 0;
			int brr[50000], crr[50000], max_diff = -1, max_diff_id = -1;
			for (int i = 0; i < n; i++) {
				if (club[i] == 2) {
					if (j < c - n / 2) {
						brr[j] = i;
						crr[j] = arr[i][2] - arr[i][1] > arr[i][2] - arr[i][0] ?
							arr[i][2] - arr[i][0] : arr[i][2] - arr[i][1];
						if (max_diff < crr[j]) {
							max_diff_id = j;
							max_diff = crr[j];
						}
						club[i] = arr[i][2] - arr[i][1] < arr[i][2] - arr[i][0] ? 1 : 0;
						j++;
					} else {
						if ((arr[i][2] - arr[i][1] > arr[i][2] - arr[i][0] ?
							arr[i][2] - arr[i][0] : arr[i][2] - arr[i][1]) < max_diff) {
							club[brr[max_diff_id]] = 2;
							brr[max_diff_id] = i;
							crr[max_diff_id] = arr[i][2] - arr[i][1] > arr[i][2] - arr[i][0] ?
							arr[i][2] - arr[i][0] : arr[i][2] - arr[i][1];
							max_diff_id = findmax(crr, c - n / 2);
							max_diff = crr[max_diff_id];
						}
					}
				}
			}
			for (int i = 0; i < c - n / 2; i++) ans -= crr[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
