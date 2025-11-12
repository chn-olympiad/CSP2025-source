#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],b=0,c=0,d=0,e=0;
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
		if(i==1)
		{
			b=a[i];
		}
	}
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
			c=i;
	}
	if(c>m)
	{	
		d=c%m;
		e=c/m;
		if((e+1)%2==0)
		{
			cout<<e+1<<" "<<n-d+1;
		}
		else
		{
			
			cout<<e+1<<" "<<d;
		}
	}
	else
	{
		
		cout<<1<<" ";
		if(d==0)
			cout<<c;
		else
			cout<<d;
	}
	return 0;
}
