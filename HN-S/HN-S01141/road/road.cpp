#include<bits/stdc++.h>
using namespace std;
int lca(int x,int y) 
{
	
} 
int main()
{
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int f[n+1][n+1];
	memset(f,0,sizeof(f)); 
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			f[x][y]=f[y][x]=z;
		}
		
	} 
	return 0;
}
