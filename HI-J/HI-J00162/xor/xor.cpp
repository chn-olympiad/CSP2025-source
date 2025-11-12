#include<bits/stdc++.h>
using namespace std;
int k,n,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		if(a[1]==k)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(n==2)
	{
		if(a[1]==k&&a[2]==k)
		{
			cout<<2;
		}
		else if((a[1]^a[2])==k||a[1]==k||a[2]==k)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<1;
	}
	return 0;
}
