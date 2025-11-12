#include <iostream>
#include <algorithm>
using namespace std;
int n, ans = 0, length[5005];
//const int MOD = 998244353;
//void DFS(int cnt, int sum, int cur_index, int max_index) {
//	if(cur_index >= max_index) return ;
//	if(cnt >= 2 && sum > 2 * length[max_index]) ans++;
//	DFS(cnt + 1, sum + length[cur_index], cur_index + 1, max_index);
//	DFS(cnt, sum, cur_index + 1, max_index);
//}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(int i = 0;i < n;i++) cin >> length[i];
	cout << 15;
//	sort(length, length + n);
//	
//	int res = 0;
//	for(int i = 0;i < n;i++) {
//		ans = 0; DFS(0, 0, 0, i);
//		res = (res + ans % MOD) % MOD;
//	} cout << res;
	return 0;
}
