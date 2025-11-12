#include<bits/stdc++.h>
using namespace std;
int n,m,seats[15][15],a[105],t=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	if(n==1&&m==1)
	{
		cout<<'1'<<" "<<'1';
		return 0;
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=20;i++)
	{
		if(f==a[i])
		{
			f=i;
			break;
		}
	}
	if(n==1)
	{
		cout<<f<<" "<<'1';
	}
	else
	{
		cout<<'1'<<" "<<f;
	}
	return 0;
}
