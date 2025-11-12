#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool kjkklj=1;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]!=0)
			kjkklj=0;
	}
	if (k==0&&kjkklj)
	{
		cout << n;
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		if (a[i]==k)
		{
			cnt++;
			continue;
		}
		if ((a[i]==1&&a[i+1]==1)||(a[i]==0&&a[i+1]==0))
		{
			p=0;
		}
		else
		{
			p=1;
		}
		if (k==p)
		{
			cnt++;
			i++;
		}
	}
	cout << cnt;
	return 0;
}
