#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			if(((i/n)+1)%2)
			{
				cout<<i%n+1<<' '<<((i/n)+2);
			}
			else
			{
				cout<<n-(i%n+1)<<' '<<((i/n)+1);
			}
			break;
		}
	}
	return 0; 
}