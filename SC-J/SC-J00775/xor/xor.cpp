#include <bits/stdc++.h>
using namespace std;

int n,a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxn = 0,minn = 2e9;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	cout << maxn - minn;
	return 0;
}