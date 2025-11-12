#include<bits/stdc++.h>
using namespace std;
int a[1005]={0};
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			if((i/n)%2==0)
			{
				if(i%n==0)
				{
					cout<<i/n<<" "<<1;
					return 0;
				}
				else
				{
					cout<<i/n+1<<" "<<i%n;
					return 0;
				}
			}
			else
			{
				if(i%n==0)
				{
					cout<<i/n<<" "<<n;
					return 0;
				}
				else
				{
					cout<<i/n+1<<" "<<n-i%n+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
