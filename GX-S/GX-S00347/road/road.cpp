#include<bits/stdc++.h>
using namespace std;
int n,m,K;
int as,bs,cs,ans,pd;
long long f[10011][10011];
int main()
{
	
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>K;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=3276777777777777777;
		cin>>n;
			for(int i=1;i<=m;i++)
			{
				int x,y,z;
				cin>>x>>y>>z;
				f[y][x]=f[x][y]=z;
			}
			
		if(K==0)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++)
						f[i][j]=f[j][i]=min(f[i][k]+f[k][j],f[i][j]);
						
			for(int i=1;i<=n-1;i++)
				for(int j=i;j<=n;j++)
					ans=ans+f[i][j];
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=K;i++)
			{
				int z,y;
				cin>>z;
				f[i+n][0]=f[0][i+n]=z;
				for(int j=1;j<=n;j++)
				{
						cin>>y;
					f[j][i+n]=f[i+n][j]=y;
				}
				
			}
			if(K==1)
			{
				for(int i=1;i<=n+1;i++)
					for(int j=1;j<=n+1;j++)
						for(int k=1;k<=n+1;k++)
							f[i][j]=f[j][i]=min(f[i][k]+f[k][j],f[i][j]);
				for(int i=1;i<=n-1;i++)
					for(int j=i;j<=n;j++)
						ans=ans+f[i][j];
			}
			
		
		
		}
		return 0;
}
