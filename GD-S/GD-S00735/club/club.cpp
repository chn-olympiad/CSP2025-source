#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct S
{
	int id,zh;
	long long num;
}a[N];
int T,f[N][4],vis[N];
long long n,ans;
bool cmp(S x,S y)
{
	return x.num>y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		int cnt=0;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[++cnt].num>>a[++cnt].num>>a[++cnt].num;
			a[cnt].id=a[cnt-1].id=a[cnt-2].id=i;
			a[cnt].zh=3;
			a[cnt-1].zh=2;
			a[cnt-2].zh=1;
		}
		sort(a+1,a+cnt+1,cmp);
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=cnt;i++)
		{
			if(vis[a[i].id]) continue;
			if(a[i].zh==1)
			{
				if(cnt1!=n/2)
				{
					ans+=a[i].num;
					cnt1++;
					vis[a[i].id]=1;
				}
				else
				{
					continue;
				}
			}
			else if(a[i].zh==2)
			{
				if(cnt2!=n/2)
				{
					ans+=a[i].num;
					cnt2++;
					vis[a[i].id]=1;
				}
				else
				{
					continue;
				}
			}
			else if(a[i].zh==3)
			{
				if(cnt3!=n/2)
				{
					ans+=a[i].num;
					cnt3++;
					vis[a[i].id]=1;
				}
				else
				{
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
} 
