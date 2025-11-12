#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+1;
int n,k;
int a[N];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (k==0)
	{
		ans = 1;
	}
	else if (k==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1) ans++;
		}
	}
	cout << ans;
	return 0;
}
