#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n,a[5003];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort (a+1,a+1+n);
	cout << a[1];
	return 0;
}
