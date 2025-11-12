#include<bits/stdc++.h>
using namespace std;
const int range=1e5+5;
int len,rec[range];
int t,n,op,ans,num[4];
struct unit
{
	int chs;
	int v[4];
}a[range];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0,len=0,op=3;
		num[0]=num[1]=num[2]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].v[0],&a[i].v[1],&a[i].v[2]);
			if(a[i].v[0]>=a[i].v[1] && a[i].v[0]>=a[i].v[2])
			{
				a[i].chs=0;
				num[0]++;
			}
			else if(a[i].v[1]>=a[i].v[0] && a[i].v[1]>=a[i].v[2])
			{
				a[i].chs=1;
				num[1]++;
			}
			else
			{
				a[i].chs=2;
				num[2]++;
			}
			ans+=max(a[i].v[0],max(a[i].v[1],a[i].v[2]));
		}
		if(num[0]>n/2) op=0;
		if(num[1]>n/2) op=1;
		if(num[2]>n/2) op=2;
		if(op!=3)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].chs==op)
				{
					rec[++len]=min(
					a[i].v[a[i].chs]-a[i].v[(a[i].chs+1)%3],
					a[i].v[a[i].chs]-a[i].v[(a[i].chs+2)%3]);
				}
			}
			sort(rec+1,rec+1+len);
			int cnt=1;
			while(num[op]>n/2)
			{
				num[op]--;
				ans-=rec[cnt++];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
