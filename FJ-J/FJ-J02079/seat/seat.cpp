#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for (int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;++i)
	{
		if (a[i]==t)
		{
			if (i%n==0)
			{
				cout<<i/n<<" ";
				if (i/n%2==0)
				{
					cout<<1;
				}
				else
				{
					cout<<m;
				}
			}
			else
			{
				cout<<i/n+1<<" ";
				if ((i/n+1)%2==0)
				{
					cout<<m-i%n+1;
				}
				else
				{
					cout<<i%n;
				}
			}
		}
	}
	return 0;
}
