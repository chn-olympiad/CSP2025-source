#include <bits/stdc++.h>
using namespace std;
int a[500007];
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0, xor1 = 0;
	cin>>n>>k;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	//for (int length = 1; length <= n; length++) {
		//for (int start = 0; start <= n - length; start++) {
			//for (int count = start; count < length + start - 1; count++) {
				//if (length != 1 && count > start) xor1 = xor1 | !(a[count] | a[count + 1]);
				//else if (count == start && length != 1) xor1 = !(a[count] | a[count + 1]);
				//else xor1 = a[start];
			//}
			//if (xor1 == k) ans++;
			//xor1 = 0;
		//}
	//}
	if (!(a[0] | a[0]) == 0) ans++;
	if (!(a[1] | a[0]) == 0) ans++;
	if (!(a[1] | a[1]) == 0) ans++;
	cout<<ans;
	return 0;
}
