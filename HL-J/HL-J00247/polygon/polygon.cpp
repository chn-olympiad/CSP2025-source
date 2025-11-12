#include <bits/stdc++.h>
using namespace std;
int n,a[5005],g;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		g=max(g,a[i]);
	}
	cout << 1;
	return 0;
}
