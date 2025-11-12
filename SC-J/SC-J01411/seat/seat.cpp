#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,m;
int flag;
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
		cin>>a[i];
	}
	flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=0;
	int t;
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i]<<" ";
		if(a[i]==flag)
		{
			t=i;
			break;
		}
	}
//	cout<<"---------\n";
	if(t%n==0)
	{
		y=t/n;
		if(y%2==1)
		{
			x=n;
		}
		else
		{
			x=1;
		}
	}
	else
	{
		y=t/n+1;
//		cout<<y<<"---------";
		if(y%2==1)
		{
			x=t-n*(t/n);
		}
		else
		{
			x=n-(t-n*(t/n))+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}