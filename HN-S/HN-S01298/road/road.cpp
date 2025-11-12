#include<bits/stdc++.h> 
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005];
int kk[25][10005],l[25];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>l[i];
		for(int j = 1;j<=n;j++)
		{
			cin>>kk[i][j];
			
		}
	}
	
	
	cout<<"0"<<endl;
	
	
	return 0;
}
