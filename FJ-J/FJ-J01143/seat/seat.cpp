#include <iostream>
#include <algorithm>
using namespace std;
int n,m,p;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
		if(i==1)
		{
			p=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1; i<=n*m; i++)
	{
		if(p==a[i])
		{
			if((i/n)%2==0)
			{
				if(i%n==0)
				{
					cout<<i/n<<" "<<1;
				}
				else
				{
					cout<<i/n+1<<" "<<i%n;
				}
			}
			else
			{
				if(i%n==0)
				{
					cout<<i/n<<" "<<n;
				}
				else
				{
					cout<<i/n+1<<" "<<n-(i%n)+1;
				}
			}
		}
	}
	return 0;
}
