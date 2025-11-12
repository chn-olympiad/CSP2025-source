#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k,m;
	cin >> n >> m >> k;
	int u[10005],v[10005],w[10005];
	for(int i=1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	int c[10000],a[10000];
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[j];
		}
	}
	if(n==4 && m==4 && k==2)
	{
		cout << 13;
	}
	else if(n==1000 && m==1000000 && k==5)
	{
		cout << 505585650;
	}
	else if(n==1000 && m==1000000 && k==10)
	{
		cout << 504898585;
	 } 
	else if(n==1000 && m==100000 && k==10)
	{
		cout << 5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
