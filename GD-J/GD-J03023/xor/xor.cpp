#include<bits/stdc++.h>
using namespace std;

int n, k, ans, temp;
int arr[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++) {
		if(arr[i] == k) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
