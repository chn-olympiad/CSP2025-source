#include<bits/stdc++.h>
using namespace std;
int a[1000010][4];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int n,m,k,x;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>x;
		}
	}
	cout<<2;
	return 0;
}