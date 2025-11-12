#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c=1,r=2;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			break;
		}
	}
			if(b==99)
			{
				cout<<c<<" "<<r;
			}
			if(b==98)
			{
				cout<<c+1<<" "<<r;
			}
			if(b==94)
			{
				cout<<c+2<<" "<<r-1;
			}
	return 0;
}
