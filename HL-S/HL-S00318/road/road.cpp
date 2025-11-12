#include <bits/stdc++.h>
using namespace std;
int i,j;
int a[1000][1000];
int main()
{
	int sum=0;
	cin>>sum;
	int min;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			MIN=min(a[i+1][j],a[i][j])
			sum+=MIN;
		}
	}
	cout<<sum;
}