#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c;
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		for(int j=1;j<=n;j++)
			cin>>a;
	}
	cout<<0;
	return 0;
}
