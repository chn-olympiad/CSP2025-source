#include <bits/stdc++.h>

using namespace std;

int n, k, a[500010], chosen[500010], t, res, tempend, startPs[500010], endPs[500010];
//vector <int> startPs, endPs;
//vector <int> emptyV;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	a[0] = 0;
	chosen[0] = 0;
	res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		a[i] = (a[i - 1] ^ t);  // prefix sum
		chosen[i] = (chosen[i - 1] + (t == k));
		res += (t == k);
	}
	for (int len = 2; len <= n; len++) {
//		startPs = emptyV;
//		endPs = emptyV;
		tempend = 0;
		for (int start = 1; (start + len - 1) <= n; start++) {
			int end = start + len - 1;
			if (chosen[end] - chosen[start - 1]) {
				continue;
			}
			if ((a[end] ^ a[start - 1]) == k) {
				res++;
//				startPs.push_back(start);
//				endPs.push_back(end);
				startPs[tempend] = start;
				endPs[tempend++] = end;
				start = end + 1;
			}
		}
		for (int i = 0; i < tempend; i++) {
			for (int j = startPs[i]; j <= endPs[i]; j++) {
				chosen[j] = chosen[j - 1] + 1;
			}
			for (int j = endPs[i] + 1; j <= n; j++) {
				chosen[j] = chosen[j - 1];
			}
		}
	}
	cout << res << endl;
	return 0;
}


//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, k, a[500010], chosen[500010], t, res, tempend, startPs[500010], endPs[500010], dp[500010];
////vector <int> startPs, endPs;
////vector <int> emptyV;
//
//int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin >> n >> k;
//	a[0] = 0;
//	chosen[0] = 0;
//	res = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> t;
//		a[i] = (a[i - 1] ^ t);  // prefix sum
////		chosen[i] = (chosen[i - 1] + (t == k));
////		res += (t == k);
////		if (t == k) {
////			dp[i]++;
////		}
//	}
//	for (int j = 1; j <= n; j++) {
//		for (int i = j; i >= 1; i--) {
//			if ((a[j] ^ a[i - 1]) == k) {
//				dp[j] = max(dp[j], dp[i - 1] + 1);
//				res = max(res, dp[j]);
//			}
//		}
//	}
////	for (int len = 2; len <= n; len++) {
//////		startPs = emptyV;
//////		endPs = emptyV;
////		tempend = 0;
////		for (int start = 1; (start + len - 1) <= n; start++) {
////			int end = start + len - 1;
////			if (chosen[end] - chosen[start - 1]) {
////				continue;
////			}
////			if ((a[end] ^ a[start - 1]) == k) {
////				res++;
//////				startPs.push_back(start);
//////				endPs.push_back(end);
////				startPs[tempend] = start;
////				endPs[tempend++] = end;
////				start = end + 1;
////			}
////		}
////		for (int i = 0; i < tempend; i++) {
////			for (int j = startPs[i]; j <= endPs[i]; j++) {
////				chosen[j] = chosen[j - 1] + 1;
////			}
////			for (int j = endPs[i] + 1; j <= n; j++) {
////				chosen[j] = chosen[j - 1];
////			}
////		}
////	}
//	cout << res << endl;
//	return 0;
//}
