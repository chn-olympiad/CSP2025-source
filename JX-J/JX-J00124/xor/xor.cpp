#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

int n, k, arr[N], pre[N], limit = 0, answer = 0;
map<int, int> last;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	pre[0] = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] ^ arr[i];
	}
	
	// for (int i = 0; i <= n; i++) {
	//     cout << pre[i] << " \n"[i == n];
	// }
	
	last[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (last.count(pre[i] ^ k) == 0 || last[pre[i] ^ k] < limit) {
			last[pre[i]] = i;
		} else {
			answer++;
			limit = i;
			last[pre[i]] = i;
			
			// cout << "Matched : " << last[pre[i] ^ k] << " " << i << "\n\n";
		}
		
		// cout << "Limit = " << limit << " " << "answer = " << answer << "\n";
		// for (auto var : last) {
		//  	cout << var.first << " " << var.second << "\n";
		// }
		// cout << "\n";
	}
	
	cout << answer << "\n";
	
	return 0;
}
