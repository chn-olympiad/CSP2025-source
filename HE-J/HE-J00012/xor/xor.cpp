#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b,c;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1)
		{
			b++;
		}
		if (a[i]==0)
		{
			c++;
		}
	}
	if (b+c==n)
	{
		if (c==0)
		{
			cout<<n/2;
		}
		else
		{
			if (k==1) cout<<min(b,c);
			else cout<<(b/2+c/2);
		}
	}
	return 0;
}
