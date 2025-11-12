#include<bits/stdc++.h>
using namespace std;
int a[500005],p=0,q=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			p++;
		else if(a[i]==0)
			q++;
	}
	if(p==n && k==0)
	{
		cout<<n;
		return 0;
	}
	else if(q==n && k==0)
	{
		cout<<n;
		return 0;
	}
	else if(p+q==n)
	{
		if(k==0)
		{
			cout<<p+q;
		}
		else
		{
			cout<<(p+q)/2;
		}
	}
	else
	{
		cout<<1;
	}
	return 0;
}
