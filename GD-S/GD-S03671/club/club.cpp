#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=100010;
int n,T,tot[4],bel[N],a[N][4],nn[4][N];
bool cmp(int x,int y)
{
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])>min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(int x,int y)
{
	return a[x][2]-a[x][3]>a[y][2]-a[y][3];
}
bool cmp3(int x,int y)
{
	return a[x][3]-a[x][2]>a[y][3]-a[y][2];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			int s1=0,t=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>s1) s1=a[i][j],t=j;
			nn[t][++tot[t]]=i;
		}
		
		if(tot[1]>n/2)
		{
			sort(nn[1]+1,nn[1]+tot[1]+1,cmp);
			while(tot[1]>n/2)
			{
				int x=nn[1][tot[1]];
				tot[1]--;
				if(a[x][1]-a[x][2]<a[x][1]-a[x][3]) nn[2][++tot[2]]=x;
				else nn[3][++tot[3]]=x;
			}
		}
		if(tot[2]>n/2)
		{
			sort(nn[2]+1,nn[2]+tot[2]+1,cmp2);
			while(tot[2]>n/2)
			{
				int x=nn[2][tot[2]];
				nn[3][++tot[3]]=x;
				tot[2]--;
			}
		}
		if(tot[3]>n/2)
		{
			sort(nn[3]+1,nn[3]+tot[3]+1,cmp3);
			while(tot[3]>n/2)
			{
				int x=nn[3][tot[3]];
				nn[2][++tot[2]]=x;
				tot[3]--;
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=tot[i];j++) ans+=a[nn[i][j]][i];
		printf("%d\n",ans);
	}
	return 0;
}
/*
*/
