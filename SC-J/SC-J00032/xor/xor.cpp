#include <bits/stdc++.h>
#define int long long
using namespace std;

const int limit = 5e6 + 10;
int length, target, res;
int arr[limit];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> length >> target;
	
	int cnt = 0, other = 0;
	
	for (int pos = 1; pos <= length; pos++) {
		cin >> arr[pos];
		if (arr[pos] == 1) cnt++;
		else if (arr[pos] != 0) other++;
	}
	
	if (cnt == length && target == 0) return cout << length / 2 << '\n', 0;
	else if (other == 0) {
		int cnt0 = 0, cnt1 = 0;
		if (target == 0) {
			for (int pos = 1; pos <= length; pos++) {
				if (arr[pos] == 0) cnt0++;
				else cnt1++;
			}
			return cout << cnt1 / 2 + cnt0 << '\n', 0;
		} else if (target == 1) {
			for (int pos = 1; pos <= length; pos++) 
				if (arr[pos]) cnt1++;
			cout << cnt1 << '\n';
		}
	} else cout << 0 << '\n';
	
	return 0;
}