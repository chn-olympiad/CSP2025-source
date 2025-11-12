# include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int t,n,a[N][4],f[N][N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= n; j++)
				for (int k = n/2; k >= 1; k--)
					f[j][k] += max(f[j-1][k],f[j][k-1] + a[j][i]);
		int maxx = 0;		
		for (int k = n/2; k >= 1; k--) maxx = max(maxx,f[n][k]);
		printf("%d\n",maxx);
		memset(f,0,sizeof(f));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
