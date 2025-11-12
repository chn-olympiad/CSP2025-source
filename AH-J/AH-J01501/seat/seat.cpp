#include<bits/stdc++.h>
using namespace std;
int a[105],r,s;
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
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(r==a[i])
		{
			s=i;
			break;
		}
	}
	
	if(s%n==0)
	{
		int t=s/n;
		if(t%2==0)
			cout<<t<<' '<<1;
		else
			cout<<t<<' '<<n;
	}
	else
	{
		int t=s/n+1;
		int t1=s-(t-1)*n;
		if(t%2==0)
			cout<<t<<' '<<n-t1+1;
		else
			cout<<t<<' '<<t1;
	}
	return 0;
}
