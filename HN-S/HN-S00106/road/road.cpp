#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005][10005],cost,judge[10005],jxw[10005];
bool check()
{
	for(int i=1;i<=n;i++) if(judge[i]==0) return false;
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	int xjxw;
	for(int i=1;i<=k;i++) 
	{
		cin>>xjxw;
		for(int j=1;j<=n;j++) cin>>jxw[j];
	}
	for(int i=1;i<=n;i++)
	{
		long long to,f=1e9;
		for(int j=1;j<=n;j++) 
			if(a[i][j]!=0&&f>a[i][j]) 
				{
					to=j;
					f=a[i][j];
					a[i][j]=1e9;
					a[j][i]=1e9;
				}
		cost+=f;
		judge[i]=1;
		judge[to]=1;
		if(check()==true) break;
	}
	cout<<cost;
	return 0;
}
