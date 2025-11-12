#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],n,k;
struct abc
{
	int l,r;
}c[30000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<' ';
	}
	int ans=1,t=0;	
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i>0;i--)
		{
			if((b[j]^b[i-1])==k)
			{
				c[++t].l=i;
				c[t].r=j;
				break;
			}
		}
	}
	int e=c[1].r;
	//cout<<t;
	for(int i=2;i<=t;i++)
	{
		if(c[i].l>e)
		{
			ans++;
			e=c[i].r;
			//cout<<i<<' ';
		}
	}
	cout<<ans;
	return 0;
}
