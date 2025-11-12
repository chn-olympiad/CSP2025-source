#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=1,r=1;
	while (r<=n)
	{
		int sum=0;
		for (int i=l;i<=r;i++) sum^=a[i];
		if (sum==k)
		{
			ans++;
			l=r;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}