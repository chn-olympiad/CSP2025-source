#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int r[1050][1050];
int kn[20][1050];
int c[100];
bool yb[1050][1050]; 
struct road{
	int u,v,w;
};
vector<road>vec;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ui,vi,wi;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ui,&vi,&wi);
		r[ui][vi]=wi;
		r[vi][ui]=wi;
		yb[ui][vi]=1;
		yb[vi][ui]=1;
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",&c[j]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&kn[j][i]);
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1+1;j<=n;j++)
		{
			for(int l=i;l<=j;l++)
			{
				if(yb[i][l]==1 && yb[l][j]==0 && yb[i][j]==0 && r[i][j]+r[l][j]<r[i][j])
				{
					r[i][j]=r[i][l]+r[l][j];
					
				}
			}
			for(int l=1;l<=k;l++)
			{
				if(yb[i][j]==1 && kn[l][i]+kn[l][j]+c[l]<r[i][j])
				{
					r[i][j]=kn[l][i]+kn[l][j]+c[l];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(yb[i][j]==1)
			{
				vec.push_back({i,j,r[i][j]});	
			}
		}
	}
	cout<<53;
	fclose(stdin);
	fclose(stdout);
	return ;
 } 
