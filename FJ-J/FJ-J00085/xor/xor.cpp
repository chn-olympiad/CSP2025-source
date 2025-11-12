#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500009], sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (a[i] == k) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
