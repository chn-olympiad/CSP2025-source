#include<bits/stdc++.h>
using namespace std;
int t,n,sum,tot;
int cnt[3];
struct Node
{
	int a1,a2,a3,id;
}a[200005];
struct Node1
{
	int cha;
}b[200005];
bool cmp(Node1 &a,Node1 &b)
{
	return a.cha<b.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3)cnt[1]++,sum+=a[i].a1,a[i].id=1;
			else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3)cnt[2]++,sum+=a[i].a2,a[i].id=2;
			else if(a[i].a3>a[i].a1&&a[i].a3>a[i].a2)cnt[3]++,sum+=a[i].a3,a[i].id=3;
		}
		if(cnt[1]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].id==1)b[++tot].cha=a[i].a1-max(a[i].a2,a[i].a3);
			sort(b+1,b+tot+1,cmp);
			for(int i=1;i<=cnt[1]-n/2;i++)
			{
				sum=sum-b[i].cha;
			}
		}
		else if(cnt[2]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].id==2)b[++tot].cha=a[i].a2-max(a[i].a1,a[i].a3);
			sort(b+1,b+tot+1,cmp);
			for(int i=1;i<=cnt[2]-n/2;i++)
			{
				sum=sum-b[i].cha;
			}
		}
		else if(cnt[3]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(a[i].id==3)b[++tot].cha=a[i].a3-max(a[i].a2,a[i].a1);
			sort(b+1,b+tot+1,cmp);
			for(int i=1;i<=cnt[3]-n/2;i++)
			{
				sum=sum-b[i].cha;
			}
		}
		printf("%d\n",sum);
		sum=tot=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			a[i].a1=a[i].a2=a[i].a3=a[i].id=0;
			b[i].cha=0;
		}
	}
	return 0;
}
