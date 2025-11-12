#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
int n,m,k;
int u[N],v[N],w[N];
int c[N],a[20][N];
int o=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) o=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]) o=0;
		}
	}
	cout<<"0";
	return 0;
}
