#include<algorithm> 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
struct st
{
	bool fl;
	int fen; 
}a[1000];
bool cmp(st a,st b)
{
	return a.fen>b.fen;
}
int main()
{
	freopen("seat.in","s",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i].fen;
		if(i==1)
		{
			a[i].fl=true;
		}
		else
		{
			a[i].fl=false;
		}
	}
	int s;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].fl==true)
		{
			s=i;
		}
	}
	int t=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t++;
			if(t==s)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		if(i>m) break;
		for(int j=n;j>=1;j--)
		{
			t++;
			if(t==s)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}