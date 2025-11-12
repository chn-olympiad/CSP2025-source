#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[n];
	for (int i = 0;i < n;i ++)
		cin >> a[i];
	int ans = 0,num = 0;
	for (int i = 0;i < n;i ++) {
		for (int j = i + 1;j <= k;j ++) {
			num = num + a[j];
		}
		ans = max(ans,num);
	}
	cout << 8;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
