#include <bits/stdc++.h>
using namespace std;
bool q(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	int c=n*m,d=0;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	d=a[1];
	int e=0;
	sort(a+1,a+c+1,q);
	for(int i=c;i>=1;i--)
	{
		if(a[i]==d)
		{
			e=i;
		}
	}
	if(e%n==0)
	{
		if(((e/n)%2)==0)
		{
			cout<<e/n<<' '<<1;
		}
		else
		{
			cout<<e/n<<' '<<n;
		}
	}
	else
	{
		if(((e/n+1)%2)==0)
		{
			cout<<e/n+1<<' '<<n-e%n;
		}
		else
		{
			cout<<e/n+1<<' '<<e%n;
		}
	}
	return 0;
} 
