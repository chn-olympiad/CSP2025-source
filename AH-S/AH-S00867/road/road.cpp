#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[10010][10010],f[10010][10010],a,b,fcoside[50],wcoside[50],roadside[50][10010];
int cost(int coming,int where)
{
	int flag=0;
	int citycost=100000000,countrysidecost=100000000;
	for(int i=1;i<=n;i++)
	{
		if(i!=where&&f[where][i]==0&&w[where][i]!=0)
		{
			flag=1;
			f[where][i]=1;
			f[coming][i]=1;
			f[i][where]=1;
			f[i][coming]=1;
			citycost=min(citycost,cost(where,i)+w[where][i]);
			f[where][i]=0;
			f[coming][i]=0;
			f[i][where]=0;
			f[i][coming]=0;
		}
	}
	if(flag==0)
	{
		return flag;
	}
	for(int i=1;i<=k;i++)
	{
		if(fcoside[i]==0)
		{
			fcoside[i]=1;
			for(int j=1;j<=n;j++)
			if(j!=where&&f[where][j]==0&&w[where][j]!=0)
			{
				f[where][j]=1;
				f[coming][j]=1;
				f[j][where]=1;
				f[j][coming]=1;
				countrysidecost=min(countrysidecost,cost(where,j)+roadside[i][j]+roadside[i][where]+wcoside[i]);
				f[where][j]=0;
				f[coming][j]=0;
				f[j][where]=0;
				f[j][coming]=0;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			if(j!=where&&f[where][j]==0&&w[where][j]!=0)
			{
				f[where][j]=1;
				f[coming][j]=1;
				f[j][where]=1;
				f[j][coming]=1;
				countrysidecost=min(countrysidecost,cost(where,i)+roadside[i][j]);
				f[where][j]=0;
				f[coming][j]=0;
				f[j][where]=0;
				f[j][coming]=0;
			}
		}
		fcoside[i]=0;
	}
	return min(citycost,countrysidecost);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		cin>>w[a][b];
		w[b][a]=w[a][b];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>wcoside[i];
		for(int j=1;j<=n;j++)
		{
			cin>>roadside[i][j];
		}
	}
	cout<<cost(1,1);
}
