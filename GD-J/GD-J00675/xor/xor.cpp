#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int a[n]; 
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << floor(n / 2);
	return 0;
}
