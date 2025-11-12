#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			t=i;
			break;
		} 
	}
	if(t%n==0)
	{
		cout<<t/n<<' ';
		if((t/n)%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<1;
		}
	}
	else if((t/n)%2==0)
	{
		cout<<t/n+1<<' '<<t%n;
	}
	else
	{
		cout<<t/n+1<<' '<<n-(t%n)+1;
	}
	return 0;
}
