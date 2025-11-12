#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,m,r,x;
int a[105];

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			x=i;
			break;
		}
	}
	int i,j;
	if(x%n==0)
	{
		j=x/n;
	}
	else
	{
		j=x/n+1;
	}
	if(j%2==0)
	{
		i=n*j-x+1;
	}
	else
	{
		i=n-(n*j-x);
	}
	cout<<j<<" "<<i;
	return 0;
}