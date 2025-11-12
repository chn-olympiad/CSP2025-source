#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5],num[5][N],cnt[5],la[N];
long long ans;
struct edge
{
	int max1,max2,i,i1,i2;
}st[N];
bool cmp(edge x,edge y)
{
	return x.max1>y.max1;
}
int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		memset(num,0,sizeof(num));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			st[i].i=i;
			if(a[i][1]>=a[i][2] && a[i][2]>=a[i][3]) st[i].i1=1,st[i].i2=2,st[i].max1=a[i][1],st[i].max2=a[i][2];
			if(a[i][1]>=a[i][3] && a[i][3]>=a[i][2]) st[i].i1=1,st[i].i2=3,st[i].max1=a[i][1],st[i].max2=a[i][3];
			if(a[i][2]>=a[i][1] && a[i][1]>=a[i][3]) st[i].i1=2,st[i].i2=1,st[i].max1=a[i][2],st[i].max2=a[i][1];
			if(a[i][2]>=a[i][3] && a[i][3]>=a[i][1]) st[i].i1=2,st[i].i2=3,st[i].max1=a[i][2],st[i].max2=a[i][3];
			if(a[i][3]>=a[i][1] && a[i][1]>=a[i][2]) st[i].i1=3,st[i].i2=1,st[i].max1=a[i][3],st[i].max2=a[i][1];
			if(a[i][3]>=a[i][2] && a[i][2]>=a[i][1]) st[i].i1=3,st[i].i2=2,st[i].max1=a[i][3],st[i].max2=a[i][2];
		}
		sort(st+1,st+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int res=st[i].i1;
			num[res][++cnt[res]]=i;
			ans+=st[i].max1*1ll;
		}
		if(cnt[1]>(n/2)||cnt[2]>(n/2)||cnt[3]>(n/2))
		{
			int ljn;
			if(cnt[1]>(n/2)) ljn=1;
			if(cnt[2]>(n/2)) ljn=2;
			if(cnt[3]>(n/2)) ljn=3;
			for(int i=1;i<=cnt[ljn];i++)
			{
				la[i]=st[num[ljn][i]].max1-st[num[ljn][i]].max2;
			}
			sort(la+1,la+cnt[ljn]+1);
			for(int i=1;i<=(cnt[ljn]-n/2);i++)
			{
				ans-=la[i]*1ll;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}//1010