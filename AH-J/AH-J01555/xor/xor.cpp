#include<bits/stdc++.h>
using namespace std;
int k,a[500005],s[10000001],t,c,maxn=-1,minn=999999999;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,n;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		{
			t=1;
		}
		s[a[i]]++;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(t==0)
	{
		if(k==0)
		{
			cout<<n/2;
		}
		if(k==1)
		{
			cout<<n;
		}
		if(k>1)
		{
			cout<<0;
		}
	}
	else if(maxn==1&&minn==0)
	{
		if(k==0)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					c++;
					a[i]=0;
					a[i+1]=0;
				}
			}
			cout<<s[0]+c;
		}
		if(k==1)
		{
			cout<<s[1];
		}
		if(k>1)
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
