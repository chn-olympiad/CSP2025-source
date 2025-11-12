#include<bits/stdc++.h>
using namespace std;
int a[101];
int nm,mn;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	nm=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==nm)
		{
			mn=i;
			break;
		}
	}
	int x,y;
	if(mn%n==0) x=mn/n;
	else x=mn/n+1;
	if(x%2==1)
	{
		if(mn%n==0) y=n;
		else y=mn-(x-1)*n;
	}
	else
	{
		if(mn%n==0) y=1;
		else y=n-(mn-(x-1)*n)+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
