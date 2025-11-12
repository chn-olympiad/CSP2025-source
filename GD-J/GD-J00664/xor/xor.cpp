#include<bits/stdc++.h>
using namespace std;
int a[500010],f[500010],t1,t;
struct st
{
	int l,r;
}h1[500010];
struct stu
{
	int l,r;
}h[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int w=n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int s=a[i];
		if(s==k)
		{
			h1[t1].l=i;
			h1[t1].r=i;
			t1++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			s=int(s^a[j]);
			if(s==k)
			{
				h1[t1].l=i;
				h1[t1++].r=j;
				break;
			}
		}
	}
	for(int i=t1-1;i>=1;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(h1[j].r==h1[i].r)
			{
				h1[j].l=-1;
				h1[j].r=-1;
			}
		}
	}
	for(int i=0;i<t1;i++)
	{
		if(h1[i].l!=-1)
		{
			h[t].l=h1[i].l;
			h[t++].r=h1[i].r;
		}
	}
	int xr=-1;
	for(int i=0;i<t;i++)
	{
		if(h[i].l<=xr)continue;
		int j=h[i].r-h[i].l+1;
		if(j>w)continue;
		f[i]=max(f[i],f[i-1]+1);
		if(f[i]==f[i-1]+1)
		{
			xr=h[i].r;
		}
		ans=max(f[i],ans);
	}
	cout<<ans;
}
