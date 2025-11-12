# include <bits/stdc++.h>
using namespace std;
int n,m,k,w,x,y,z,sum;
int a[1005][1005];
int b[1005][1005];
int d[1000005];
int cost[1000005];
bool f[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    memset(a,0x3f,sizeof(a));
    for (int i=1;i<=n;i++)
    {
    	a[i][i]=0;
	}
	for (int i=1;i<=m;i++)
 	{
		cin >> x >>y >> z;
		a[x][y]=z;
		a[y][x]=z;
		b[x][y]=z;
		b[y][x]=z;
	}
	if (k==0)
	{
	    for (int kk=1;kk<=n;kk++)
	    {
	    	for (int i=1;i<=n;i++)
	    	{
	    		for (int j=1;j<=n;j++)
	    		{
	    			a[i][j]=min(a[i][j],a[i][kk]+a[kk][j]);
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (a[i][j]!=b[i][j])
				{
					sum +=b[i][j];
				}
			}
		}
		cout << sum << endl;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> d[i] >> cost[i];
		for (int i=1;i<=n-1;i++)
		{
			cin >> w;
		}
	}
	return 0;
}
