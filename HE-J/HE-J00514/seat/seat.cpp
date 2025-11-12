#include <bits/stdc++.h>

using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r,gread;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==r)
		{
			gread=i;
			break;
		}
	}
	int a_m=gread/n;
	if(gread%n==0)
	{
		a_m--;
	}
	int a_n;
	if(a_m%2)
	{
		a_n=(n-gread%n)+1;
		if(gread%n==0)
		{
			a_n=1;
		}
	}
	else 
	{
		a_n=gread%n;
		if(gread%n==0)
		{
			a_n=n;
		}
	}
	cout<<a_m+1<<" "<<a_n;
	return 0;
}

