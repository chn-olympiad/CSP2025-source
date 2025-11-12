#include<bits/stdc++.h>
using namespace std;
int a[100005][5],f[100005][5];
int t,maxn,b[100005][5],n;
void hs(int tn)
{
	for(int j=1;j<=3;j++)
	{
		if(b[tn-1][j]<n/2)
		{
			f[tn][j]=max(max(f[tn-1][1],f[tn-1][2]),f[tn-1][3])+a[tn][j];
			b[tn][1]=b[tn-1][1];
			b[tn][2]=b[tn-1][2];
			b[tn][3]=b[tn-1][3];
			b[tn][j]++;
			if(tn==n)
			{
				if(f[tn][j]>maxn)
				{
					maxn=f[tn][j];
				}
			}
			else
			{
				hs(tn+1);
			}
			b[tn][j]--;
			f[tn][j]=0;
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		hs(1);
		printf("%d\n",maxn);
	}
	return 0;
}
