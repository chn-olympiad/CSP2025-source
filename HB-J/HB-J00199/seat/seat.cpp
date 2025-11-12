#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1],s=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+n*m);
	for(int c=1;c<=m;c++)
	{
		for(int r=1;r<=n;r++)
		{
			if(a[s]==a1)
			{
				cout<<c<<" ";
				if(c%2==0)
					cout<<n-r+1;
				else
					cout<<r;
				return 0;
			}
			s--;
		}
	}
	return 0;
}
