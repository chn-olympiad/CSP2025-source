#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct ooo
{
	int x;
	int y;
	int z;
}a[N];
int n,m,ans,s1[N],s2[N],s3[N],cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		cnt1=cnt2=cnt3=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]=(ooo){x,y,z};
		if(x>=y&&x>=z)
		{
			s1[++cnt1]=i;
			ans+=x;
		}
		else
		if(y>=x&&y>=z)
		{
			s2[++cnt2]=i;
			ans+=y;
		}
		else
		{
			s3[++cnt3]=i;
			ans+=z;
		}
	}
	for(int i=1;i<=n;i++)
	{
		s1[i]=a[s1[i]].x-max(a[s1[i]].y,a[s1[i]].z);
		s2[i]=a[s2[i]].y-max(a[s2[i]].x,a[s2[i]].z);
		s3[i]=a[s3[i]].z-max(a[s3[i]].y,a[s3[i]].x);
	}
	if(cnt1>n/2)
	{
		sort(s1+1,s1+cnt1+1);
		for(int i=1;i<=cnt1-n/2;i++)
			ans-=s1[i];
	}
	else
	if(cnt2>n/2)
	{
		sort(s2+1,s2+cnt2+1);
		for(int i=1;i<=cnt2-n/2;i++)
			ans-=s2[i];
	}
	else
	if(cnt3>n/2)
	{
//		cout<<ans<<endl;
//		cout<<"aaaa";
		sort(s3+1,s3+cnt3+1);
		for(int i=1;i<=cnt3-n/2;i++)
			ans-=s3[i];
	}
	printf("%d\n",ans);
	}
	return 0;
}
