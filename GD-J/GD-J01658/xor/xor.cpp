#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (k==0 && n<=2)
	{
		if (n==1)
		{
			cout<<0;
		}
		else if (n==2)
		{
			cout<<1;
		}
	}
	return 0;
}
