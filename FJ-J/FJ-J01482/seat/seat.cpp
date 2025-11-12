#include<bits/stdc++.h>
using namespace std;
int a[105]={0},b[105]={0};
int cmp(int x,int y)
{
	if(x>y)
	{
		swap(b[x],b[y]);
	}
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		b[i]=i;
	}
	int sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pm;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			pm=i;
		}
	}
	int zs=pm-pm%m,ck=0;
	if(pm%m==0)
		ck=0;
	else
		ck=1;
	cout<<zs/m+ck<<' ';
	if(((zs)/m+ck)%2==1)
	{
		if(ck==0)
		{
			cout<<m;
		}
		else
			cout<<pm%m;
	}
	else
		if(ck==0)
		{
			cout<<1;
		}
		else
			cout<<m-(pm%m)+1;
	return 0;
}
