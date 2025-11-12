#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005][5],b[100005];
int f[2][205][205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		int n;
		bool flag=false;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][1]||a[i][2])
			{
				flag=true;
			}
		}
		int ans=0;
		if(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][0];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--)
			{
				ans+=b[i];
			}
			printf("%d\n",ans);
			continue;
		}
		int op=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2&&j+k<=i;k++)
				{
					f[op][j][k]=0;
					if(j>=1)
					{
						f[op][j][k]=max(f[op][j][k],f[op^1][j-1][k]+a[i][0]);
					}
					if(k>=1)
					{
						f[op][j][k]=max(f[op][j][k],f[op^1][j][k-1]+a[i][1]);
					}
					if(i-j-k>=1)
					{
						f[op][j][k]=max(f[op][j][k],f[op^1][j][k]+a[i][2]);
					}
					if(i==n&&i-j-k<=n/2)
					{
						ans=max(ans,f[op][j][k]);
					}
//					printf("%d ",f[op][j][k]);
				}
//				printf("\n");
			}
//			printf("\n");
			op^=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
