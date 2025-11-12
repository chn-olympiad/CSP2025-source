#include<bits/stdc++.h>
using namespace std;	
int n,k,a[500001],b[500001],ans=0,o=0,p=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			b[i]=1;
		}
		if(a[i]==1)
		{
			o++;
		}
		if(a[i]==0)
		{
			p++;
		}
	}
	if(o==n)
	{
		cout<<n/2;
		return 0;
	}
	else if(o+p==n)
	{
		if(k==0)
		{
			cout<<p;
		}
		else
		{
			cout<<o;
		}
	}
	return 0;
}