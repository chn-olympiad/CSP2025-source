#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],i,j,p,t,y;
bool vis[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.ont","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n*m;i++)
	{
		p=-999999999;
		t=0;
		for(j=1;j<=n*m;j++)
		{
			if(vis[j]==0&&a[j]>p)
			{
				vis[t]=0;
				p=a[j];
				t=j;
				vis[j]=1;
			}
		}
		a[t]=i;
		vis[t]=1;
		if(t==1)
		break;
	}
	y=a[1];
	if(y%n==0)
	{
		cout<<y/n<<' ';
		if((y/n)%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<y/n+1<<' ';
		if((y/n+1)%2==1)
		{
			cout<<y%n;
		}
		else
		{
			cout<<n+1-y%n;
		}
	}
	return 0;
}
