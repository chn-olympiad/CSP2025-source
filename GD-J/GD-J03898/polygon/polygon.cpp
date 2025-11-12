#include <bits/stdc++.h>
using namespace std;
long long a=0,g=0;
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n,l[5005],cntl=0,f;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i]==1) cntl++;
	}
	f =n;
	a = n;
	if(cntl==n)
	{
		for(int i=3;i<=n;i++)
		{
			for(int j=i;j>1;j++)
			{
				a*=(f-1);
			}
			f=n;
			g+=a;
		}
	}
	cout<< g%998244353;
	return 0;
}
