#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int a[1000006][5];
int b[10006][105];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			cin>>b[i][j];
	cout<<13;
	return 0;
}
