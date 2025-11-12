#include<bits/stdc++.h>
using namespace std;
int t,n,m,l1,l2,l3;
int a[100010][4];
struct Node
{
	int cnt;
	int id;
	int cha;
}b1[100010],b2[100010],b3[100010];
bool cmp(Node aa,Node b)
{
	return aa.cha>b.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l1=l2=l3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				b1[++l1].cnt=a[i][1],b1[l1].id=i;
				b1[l1].cha=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][3])
			{
				b2[++l2].cnt=a[i][2],b2[l2].id=i;
				b2[l2].cha=a[i][2]-max(a[i][1],a[i][3]);
			}
			else 
			{
				b3[++l3].cnt=a[i][3],b3[l3].id=i;
				b3[l3].cha=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		sort(b1+1,b1+l1+1,cmp);
		sort(b2+1,b2+l2+1,cmp);
		sort(b3+1,b3+l3+1,cmp);
		if(l1>n/2)
		{
			for(int i=l1;i>n/2;i--)
			{
				int id1=b1[i].id;
				if(a[id1][2]>=a[id1][3])b2[++l2].cnt=a[id1][2];
				else b3[++l3].cnt=a[id1][3];
			}
			l1=n/2;
		}
		if(l2>n/2)
		{
			for(int i=l2;i>n/2;i--)
			{
				int id2=b2[i].id;
				if(a[id2][1]>=a[id2][3])b1[++l1].cnt=a[id2][1];
				else b3[++l3].cnt=a[id2][3];
			}
			l2=n/2;
		}
		if(l3>n/2)
		{
			for(int i=l3;i>n/2;i--)
			{
				int id3=b3[i].id;
				if(a[id3][1]>=a[id3][2])b1[++l1].cnt=a[id3][1];
				else b2[++l2].cnt=a[id3][2];
			}
			l3=n/2;
		}
		long long ans=0;
		for(int i=1;i<=l1;i++)ans+=b1[i].cnt;
		//cout<<ans<<' ';
		for(int i=1;i<=l2;i++)ans+=b2[i].cnt;
		//cout<<ans<<' ';
		for(int i=1;i<=l3;i++)ans+=b3[i].cnt;
		printf("%lld\n",ans);
	}
	return 0;
}
