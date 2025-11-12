#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seatin","r",stdin)
	freopen("seatout","w",stdout)
	int m,n,a[1000][1000],j=1,c,r;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=m*n;i++)
	{
		if(i+1==m)
		{
			i=1;
			j=2;
		}
		if(a[c][r]<a[i][j])
		{
			a[c][r]=a[i][j];
		}
	}
	cout<<c<<r;
	return 0;
}
