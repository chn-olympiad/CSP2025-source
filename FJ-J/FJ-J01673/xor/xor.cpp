#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	int flag=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=1) flag=0;
	}
	if (flag==1)
	{
		if (k>1) cout<<0;
		if (k==1) cout<<n;
		if (k==0) cout<<n/2;
		return 0;
	}
	return 0;
}
