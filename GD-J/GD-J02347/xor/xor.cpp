#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int n,k,a[100010],f[100010],xian1[100010],xian2[100010],x=1,l=1;
struct ch
{
	int mi,ma,num;
};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	struct ch d[100010];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=a[1];
	if(f[1]==k)
	{
		xian1[x]=1;
		xian2[x]=1;
		x++;
	}
	for(int i=2;i<=n;i++)
	{
		f[i]=(f[i-1]^a[i]);
		if(f[i]==k)
		{
			xian1[x]=1;
			xian2[x]=i;
			x++;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if((f[i]^f[j])==k)
			{
				xian1[x]=j+1;
				xian2[x]=i;
				x++;
			}
		}
	}
	bool eck=false;
	d[l].num=1;
	d[l].mi=xian1[1];
	d[l].ma=xian2[1];
	for(int i=2;i<x;i++)
	{
		for(int j=1;j<=l;j++)
		{
			if(xian2[i]<d[j].mi||xian1[i]>d[j].ma)
			{
				eck=true;
				d[j].num++;
				d[j].mi=min(d[j].mi,xian1[i]);
				d[j].ma=max(d[j].ma,xian2[i]);
				break;
			}
		}
		if(eck==false)
		{
			l++;
			d[l].num=1;
			d[l].mi=xian1[i];
			d[l].ma=xian2[i];
		}
		eck=false;
	}
	int fan;
	for(int i=1;i<=l;i++)
	{
		fan=max(fan,d[l].num);
	}
	cout<<fan;
	return 0;
}
