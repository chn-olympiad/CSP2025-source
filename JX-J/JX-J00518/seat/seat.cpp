#include<bits/stdc++.h>
using namespace std;
int a[155];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+len);
	int wz=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==t)
		{
			wz=i;
			break;
		}
	}
	wz=len-wz+1;
	//cout<<wz<<' ';
	int x=0,y=0;
	if(wz%n==0)
	{
		x=wz/n;
	}
	else
	{
		x=wz/n+1;
	}
	if(x%2==0)
	{
		if(wz%n==0) y=1;
		else y=n-wz%n+1;
	}
	else
	{
		if(wz%n==0) y=n;
		else y=wz%n;
	}
	cout<<x<<' '<<y;
	return 0;
}
