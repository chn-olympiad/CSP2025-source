/*
55+5
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e2+10;
int T,n,ans;
struct node
{
	int v1,v2,v3;
}a[N];
int f[M][M][M];
bool cmp(node i,node j)
{
	return i.v1>j.v1;
}
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i].v2!=0||a[i].v3!=0)
			return 0;
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].v1,&a[i].v2,&a[i].v3);
		if(check())
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].v1;
			printf("%d\n",ans),ans=0;
			continue;
		}
		f[1][1][0]=a[1].v1,f[1][0][1]=a[1].v2,f[1][0][0]=a[1].v3;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k+j<=i;k++)
				{
					if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].v1);
					if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].v2);
					if(j+k<i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].v3);
					if(j<=i/2&&k<=i/2&&(i-j-k)<=i/2)
						ans=max(ans,f[i][j][k]);
				}
			}
		}
		printf("%d\n",ans),ans=0;
	}
	return 0;
}