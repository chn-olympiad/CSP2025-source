#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node
{
	int c[4];
	int fir,sec,thi;
	int ord;
	int flag;
}a[MAXN];
bool cmp1(node x,node y)
{
	return x.c[x.fir]>=y.c[y.fir];
}
bool cmp2(node x,node y)
{
	return x.c[x.sec]>=y.c[y.sec];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			a[i].ord=i;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].c[j];
			}
			if(a[i].c[1]>=a[i].c[2]&&a[i].c[2]>=a[i].c[3])
			{
				a[i].fir=1;a[i].sec=2;a[i].thi=3;
			}
			if(a[i].c[1]>=a[i].c[3]&&a[i].c[3]>=a[i].c[2])
			{
				a[i].fir=1;a[i].sec=3;a[i].thi=2;
			}
			if(a[i].c[2]>=a[i].c[1]&&a[i].c[1]>=a[i].c[3])
			{
				a[i].fir=2;a[i].sec=1;a[i].thi=3;
			}
			if(a[i].c[2]>=a[i].c[3]&&a[i].c[3]>=a[i].c[1])
			{
				a[i].fir=2;a[i].sec=3;a[i].thi=1;
			}
			if(a[i].c[3]>=a[i].c[1]&&a[i].c[1]>=a[i].c[2])
			{
				a[i].fir=3;a[i].sec=1;a[i].thi=2;
			}
			if(a[i].c[3]>=a[i].c[2]&&a[i].c[2]>=a[i].c[1])
			{
				a[i].fir=3;a[i].sec=2;a[i].thi=1;
			}
		}
		int lim=n/2;
		sort(a+1,a+1+n,cmp1);
		int cnt[4];
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i].fir]<lim)
			{
				ans+=a[i].c[a[i].fir];
				a[i].flag=1;
				cnt[a[i].fir]++;
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i].sec]<lim&&a[i].flag==0)
			{
				ans+=a[i].c[a[i].sec];
				a[i].flag=1;
				cnt[a[i].sec]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].flag==0)
			{
				ans+=a[i].c[a[i].thi];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
