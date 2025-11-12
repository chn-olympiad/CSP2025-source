#include <bits/stdc++.h>
using namespace std;

int n,k,ans,a[500005],s;
bool flag = false;

int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	s = a[1];
	for (int i = 1;i <= n + 1;i++) {
		if (s == k && i != 1) {
			ans++;
			s = a[i];
			continue;
		}
		if (i == 1) {
			continue;
		}
		s = s ^ a[i];
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
