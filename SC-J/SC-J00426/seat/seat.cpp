#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],x,b,o;
bool cmp(int c,int r)
{
	return c>r;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			o++;
			cin>>a[o];
		}
	}
	x=a[1];
	sort(a+1,a+o+1,cmp);
	for(int i=1;i<=o;i++)
	{
		if(a[i]==x)
		{
			b=i;
			break;
		}  
	}
	if(b<=n) 
	{
	cout<<1<<' '<<b;	
	}
	else
	{
		if(b%n==0)
		{
			cout <<b/n<<' '<<n;
		}
		else
	{
		if((b/n+1)%2==0)
		{
			cout<<b/n+1<<' '<<n-b%n+1;
		}
		else
		{
			if((b/n+1)%2==1)
			{
				cout <<b/n+1<<' '<<b%n;
			}
		}
	}
	}
	return 0;
}