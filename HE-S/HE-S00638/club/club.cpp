#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+3;
int T,n;
struct stu{
	int xmax,maxb,zxs;
}a[N];
bool tgm(stu x,stu y)
{
	return x.zxs<y.zxs;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int t[4];
			scanf("%d%d%d",&t[1],&t[2],&t[3]);
			a[i].xmax=max(t[1],max(t[2],t[3]));
			for(int j=1;j<=3;j++)
			{
				if(a[i].xmax==t[j])
					a[i].maxb=j;
			}
			sort(t+1,t+4);
			a[i].zxs=min(t[3]-t[1],t[3]-t[2]);
		}
		int st[4]={0,0,0,0},bj=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].xmax;
			st[a[i].maxb]++;
			if(st[a[i].maxb]>n/2)
				bj=a[i].maxb;
		}
		if(bj==0)
		{
			printf("%lld\n",ans);
			continue;
		}
		sort(a+1,a+1+n,tgm);
		for(int i=1;i<=n;i++)
		{
			if(st[bj]<=n/2)
				break;
			if(a[i].maxb==bj)
			{
				ans-=a[i].zxs;
				st[bj]--;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
