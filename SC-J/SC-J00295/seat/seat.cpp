#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a;
int gra[102];
int p;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>gra[i];
		if(i==1)
		{
			a=gra[i];
		}
	}
	sort(gra+1,gra+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(gra[i]==a)
		{
			p=i;
		}
	}
	c=p/n+(bool)p%n;
	if(c%2==0)
	{
		r=n-p%n+1;
		if(p%n==0)
		{
			r=1;
		}
	}
	else
	{
		r=p%n;
		if(p%n==0)
		{
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}