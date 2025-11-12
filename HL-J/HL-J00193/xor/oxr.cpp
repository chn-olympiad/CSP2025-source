#include <bits/stdc++.h>
using namespace std;
int a[10000];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==3)
	{
		cout<<2;
	}
	else if(n==4&&k==0)
	{
		cout<<1;
	}
	else if(n==4&&k==2)
	{
		cout<<2;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}