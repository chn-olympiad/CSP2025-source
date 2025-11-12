#include <bits/stdc++.h>
using namespace std;
int n,m;
int num,c;
int a[105];
int x,y;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num) 
		{
			c=i;
			break;
		}
	}
	if(c%n==0) 
	{
		x=c/n;
		if(x%2==0) y=1;
		else y=n;
	}
	else 
	{
		x=(c+n-1)/n;
		if(x%2==0) y=n-c%n+1;
		else y=c%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
