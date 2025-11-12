#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	int x=a[1];
	if (n==2)
	{
		if (a[1]==0 && a[2]==0)
		{
			cout<<2;
			return 0;
		}
		if ((a[2]==0 && a[1]!=0) || (a[1]==0 && a[2]!=0))
		{
			cout<<1;
			return 0;
		}
		if ((a[1]^a[2])==0)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	for (int i=2;i<=n;i++)
	{
		x^=a[i];
	}
	if (x==k) cout<<1;
	else cout<<2;
}
