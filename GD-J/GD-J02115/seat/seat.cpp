#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,xm;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","s",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			x=i;
			break;
		}
	}
	if(x%n!=0)
	{
		cout<<x/n+1;
		xm=x/n+1;
	}
	else 
	{
		cout<<x/n;
		xm=x/n;
	}
	cout<<" ";
	x=x%n;
	if(x==0)x=n; 
	if(xm%2==1)cout<<x;
	else cout<<n-x+1;
	return 0;
}

