#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				if(t==i)
				{
					t=j;
				}
				swap(a[i],a[j]);
				
			}
		}
	}
	if((t/n)%2==0)
	{
		if(t%n==0)
		{
			cout<<t/n<<" "<<1;
		}
		else cout<<t/n+1<<" "<<t%n;
	}
	else
	{
		if(t%n==0)
		{
			cout<<t/n<<" "<<m;
		}
		else cout<<t/n+1<<" "<<m-t%n+1;
	}
	return 0;
} 