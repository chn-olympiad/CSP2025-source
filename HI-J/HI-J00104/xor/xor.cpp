#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n, k;
	cin >> n >> k;
	int a[500005], idx[500005];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) ans++;
		idx[i] = 1;
	}
	int l = 1;
	for (int r = 2; r <= n; r++) {
		if(a[r]^a[l] == k&&!idx[r]) {
			ans++;
			idx[r] = 1;
		}
		a[l] == a[r]^a[l];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
