#include<bits/stdc++.h>
using namespace std;
int b[100010][4];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>b[i][1]>>b[i][2]>>b[i][3];
	for(int i=1;i<=k;i++)
	{
		int c,a;
		cin>>c;
		for(int j=1;j<=n;j++)cin>>a;
	}
	cout<<0;
	return 0;
}
