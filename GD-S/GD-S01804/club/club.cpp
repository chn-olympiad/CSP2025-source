#include<bits/stdc++.h>
using namespace std;
int t,n,maxn[200005],minn[200005],m,q[20],ans;
struct no
{
	int p,cha;
}ue[200005];
bool cmp(no x,no y)
{
	return x.cha<y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=n>>1;
		ans=0;
		q[1]=q[2]=q[3]=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			maxn[i]=a;
			minn[i]=0;
			ue[i].p=1;
			for(int j=1;j<=2;j++)
			{
				scanf("%d",&a);
				if(maxn[i]<a)
				{
					minn[i]=maxn[i];
					maxn[i]=a;
					ue[i].p=j+1;
				}
				else if(minn[i]<a)
				{
					minn[i]=a;
				}
			}
			ans+=maxn[i];
			ue[i].cha=maxn[i]-minn[i];
		}
		for(int i=1;i<=n;i++)
		{
			q[ue[i].p]++;
		}
		int d=0,cc=0;
		for(int i=1;i<=3;i++)
		{
			if(q[i]>m)
			{
				d=q[i]-m,cc=i;
				break;
			}
		}
		if(d)
		stable_sort(ue+1,ue+n+1,cmp);
		for(int i=1;d;i++)
		{
			if(ue[i].p==cc)
			ans-=ue[i].cha,d--;
		}
//		puts("");
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d\n",cha[i]);
//		}
		printf("%d\n",ans);
	}
	return 0;
}
