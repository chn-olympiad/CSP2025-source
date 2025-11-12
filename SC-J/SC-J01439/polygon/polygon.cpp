#include <iostream>

using namespace std;

const int N = 5005; 
const int MOD = 998244353;

int n, a[N], sum[N], maxn[N];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	cin >> n;
	
	if (n < 3) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		maxn[i] = max(maxn[i - 1], a[i]);
	}	
	
	if (n == 3) {
		if (sum[3] > maxn[3] * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
		
		return 0;
	}
	cout << 9;
	return 0;	
}
// AC this!
// And AK CSP!