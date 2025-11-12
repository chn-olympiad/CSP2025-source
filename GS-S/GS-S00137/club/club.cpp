#include <bits/stdc++.h>
using namespace std;
int n,t;
int a[114514],b[114514],c[114514],d[114514];
int numa,numb,numc;
long long ans;
int byd=1;
struct exact
{
	int num;
	int size;
}ex[114514];
bool cmp(exact x,exact y)
{
	return x.num<y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			d[i]=max(a[i],max(b[i],c[i]));
			ans+=d[i];
			if(d[i]==a[i])
			{
				numa++;
			}
			else if(d[i]==b[i])
			{
				numb++;
			}
			else
			{
				numc++;
			}
		}
	if(numa>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==a[i])
			{
				ex[byd].num=min(a[i]-b[i],a[i]-c[i]);
				ex[byd].size=i;	
				byd++;
			}
		}
		sort(ex+1,ex+byd,cmp);
		for(int i=1;i<=numa-n/2;i++)
		{
			ans-=ex[i].num;
		}
	}
		if(numb>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==b[i])
			{
				ex[byd].num=min(b[i]-a[i],b[i]-c[i]);
				ex[byd].size=i;
				byd++;
			}
		}
		sort(ex+1,ex+byd,cmp);
		for(int i=1;i<=numb-n/2;i++)
		{
			ans-=ex[i].num;
		}
	}
		if(numc>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==c[i])
			{
				ex[byd].num=min(c[i]-b[i],c[i]-a[i]);
				ex[byd].size=i;
				byd++;
			}
		}
		sort(ex+1,ex+byd,cmp);
		for(int i=1;i<=numc-n/2;i++)
		{	
			ans-=ex[i].num;
		}
	}
	cout << ans << endl;
	a[114514]={};
	b[114514]={};
	c[114514]={};
	d[114514]={};
	byd=1;
	ans=0;
	numa=0;
	numb=0;
	numc=0;
	ans=0;
	ex[114514]={};
	}
	return 0;
}
