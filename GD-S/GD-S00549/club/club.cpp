#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[4][200002];
int f[4][200002];
int z[6];
int maxk[200002];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int maxn=-1;
	for(int u=1;u<=t;u++)
	{
		memset(f[1],0,sizeof(f[1]));
		memset(f[2],0,sizeof(f[2]));
		memset(f[3],0,sizeof(f[3]));
		memset(a[1],0,sizeof(a[1]));
		memset(a[2],0,sizeof(a[2]));
		memset(a[3],0,sizeof(a[3]));
		memset(z,0,sizeof(z));
		cin>>n;
		maxn=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=n;i++)
		{
			f[1][i]=f[1][i-1]+a[1][i];
			f[2][i]=f[2][i-1]+a[2][i];
			f[3][i]=f[3][i-1]+a[3][i];
		}
		for(int x=0;x<=n;x++)
		{
			for(int y=x;y<=n;y++)
			{
				if((x<=(n/2))&&((y-x)<=(n/2))&&((n-y)<=(n/2)))
				{
					z[1]=f[1][x]+f[2][y]-f[2][x]+f[3][n]-f[3][y];
					maxn=max(z[1],maxn);
					z[2]=f[1][x]+f[3][y]-f[3][x]+f[2][n]-f[2][y];
					maxn=max(z[2],maxn);
					z[3]=f[2][x]+f[1][y]-f[1][x]+f[3][n]-f[3][y];
					maxn=max(z[3],maxn);
					z[4]=f[2][x]+f[3][y]-f[3][x]+f[1][n]-f[1][y];
					maxn=max(z[4],maxn);
					z[5]=f[3][x]+f[1][y]-f[1][x]+f[2][n]-f[2][y];
					maxn=max(z[5],maxn);
					z[6]=f[3][x]+f[2][y]-f[2][x]+f[1][n]-f[1][y];
					maxn=max(z[6],maxn);
				}
			}
		}
		maxk[u]=maxn;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<maxk[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
