#include <bits/stdc++.h>
using namespace std;
int cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],j,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	j=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++)
	{
		if(j==a[i])
		{
			k=i;
			break;
		}
	}
	if((k/n+1)%2==1||((k/n)%2==1&&k%n==0))
	{
		if(k%n==0)
		cout<<k/n<<" "<<n;
		else
		cout<<k/n+1<<" "<<k%n;
	}
	else
	{
		if(k%n==0)
		cout<<k/n<<" "<<'1';
		else
		cout<<k/n+1<<" "<<n-k%n+1;
	}
	return 0;
}
