#include <bits/stdc++.h>
#define MOD 998244353
typedef long long ll;
using namespace std;

int n, mx, sum;
int arr[100007];

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
		sum += arr[i];
	}
	if (sum > 2 * mx)    cout << 1;
	else   cout << 0;
	return 0;
}
