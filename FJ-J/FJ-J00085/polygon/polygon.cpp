#include <bits/stdc++.h>
using namespace std;
int n, a[5009], zd=0, sum, ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n == 3) {
		for (int i=1;i<=n;i++) {
			cin >> a[i];
			if (a[i]>zd) {
				zd=a[i];
			}
			sum+=a[i];
		}
		if (sum > zd*2) {
			cout << 1%998244353;
		}
	}
	return 0;
}
