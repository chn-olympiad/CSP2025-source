#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]a[i][j++])
				swap(a[i][j],a[i][j++]);
		}
	}
	cout<<i<<j;
	return 0;
}
