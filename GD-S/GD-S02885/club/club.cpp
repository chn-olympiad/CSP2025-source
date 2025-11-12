#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct uuu{
	int a[5],id[5],dist;
}a[N];
struct uu{
	int val,id;
}b[5];
int n,o[5][N],cnt[5];
bool cmp(int i,int j)
{
	return a[i].dist<a[j].dist;
}
bool cmp2(uu a,uu b)
{
	return a.val>b.val;
}
void init()
{
	memset(cnt,0,sizeof(cnt));
	memset(a,0,sizeof(a));
}
void solve()
{
	init();
	scanf("%lld",&n);
	int lim=n/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&b[1].val,&b[2].val,&b[3].val);
		b[1].id=1,b[2].id=2,b[3].id=3;
		sort(b+1,b+4,cmp2);
		a[i].a[0]=b[1].val,a[i].id[0]=b[1].id;
		a[i].a[1]=b[2].val,a[i].id[1]=b[2].id;
		a[i].a[2]=b[3].val,a[i].id[2]=b[3].id;
		a[i].dist=a[i].a[0]-a[i].a[1];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		o[a[i].id[0]][++cnt[a[i].id[0]]]=i;
		sum+=a[i].a[0];
	}
	int pos=0,maxx=0;
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>maxx)
		{
			maxx=cnt[i];
			pos=i;
		}
	}
	if(cnt[pos]>lim)
	{
		sort(o[pos]+1,o[pos]+1+cnt[pos],cmp);
		for(int i=1;i<=cnt[pos]-lim;i++)
		{
			int idd=o[pos][i];
			sum=sum-a[idd].a[0]+a[idd].a[1];
		}
	}
	printf("%lld\n",sum);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--) solve();
}
