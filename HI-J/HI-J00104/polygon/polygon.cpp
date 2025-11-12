#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a[5005];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n < 3) cout << 0;
	sort (a + 1, a + n + 1);
	if (n == 3) {
		if (a[1]+a[2] > a[3]) cout << 1;
		else cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
