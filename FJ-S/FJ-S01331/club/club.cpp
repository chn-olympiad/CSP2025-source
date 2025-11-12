#include<bits/stdc++.h>
//#define int long long
using namespace std;
int t,n,ans;
int a[5][100005];
int bel[100005],gs[5];
int cha[100005],cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(gs,0,sizeof gs);
		ans=cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i])bel[i]=1,gs[1]++;
			else if(a[2][i]>a[1][i]&&a[2][i]>a[3][i])bel[i]=2,gs[2]++;
			else bel[i]=3,gs[3]++;
			ans+=max(a[1][i],max(a[2][i],a[3][i]));
		}
		int id=0,ma=0;
		for(int i=1;i<=3;i++)
			if(gs[i]>ma)id=i,ma=gs[i];
		if(ma<=n/2)
		{printf("%d\n",ans);continue;}
		for(int i=1;i<=n;i++)
			if(bel[i]==id)
			{
				int mm=0;
				for(int j=1;j<=3;j++)
					if(j!=id)mm=max(mm,a[j][i]);
				cha[++cnt]=a[id][i]-mm;
			}
		sort(cha+1,cha+cnt+1);
		for(int i=1;i<=gs[id]-n/2;i++)
			ans-=cha[i];
		printf("%d\n",ans);
	}
	return 0;
}
