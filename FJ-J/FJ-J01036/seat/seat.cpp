#include <bits/stdc++.h>
using namespace std;
int n,m,fs,zw=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+3];
	for(int i=1;i<=m*n;i++)
	{
			cin>>a[i];
	}
	fs=a[1];
	for(int i=1;i<=m*n;i++)
	{
			if(fs<a[i])
			{
				zw++;
			}
	}
	int lie;
	if(zw%n==0)
	{
		lie=zw/n;
	}
	else{
		lie=zw/n+1;
	}
	int han;
	if(zw%n==0)
	{
		han=n;
	}
	else{
		han=zw%n;
	}
	if(lie%2==0)
	{
		cout<<lie<<" "<<n-han+1;
	}
	else{
		cout<<lie<<" "<<han;
	}
	return 0;
}
