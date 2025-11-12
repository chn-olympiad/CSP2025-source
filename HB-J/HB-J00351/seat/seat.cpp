#include<bits/stdc++.h>
using namespace std;
int a[105],xmdcj,xmdpm,xmh,xml;
bool cmp(int asd,int qwe)
{
	return asd>qwe;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	xmdcj=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==xmdcj)
		{
			xmdpm=i;
		}
	}
	xml=xmdpm/m;
	if(xmdpm%m!=0)
	{
		xml++;
	}
	if(xml%2==1)
	{
		xmh=xmdpm%m;
		if(xmh==0)
		{
			xmh+=m;
		}
	}
	else
	{
		xmh=n+1-xmdpm%m;
		if(xmdpm%m==0)
		{
			xmh-=m;
		}
	}
	cout<<xml<<" "<<xmh;
	return 0;
}
