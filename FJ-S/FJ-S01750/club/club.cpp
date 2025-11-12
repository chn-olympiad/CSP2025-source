#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N][5];
int mark[N],tong[N];
int ans;

int cmp(int s1,int s2)
{
	return s1>s2;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		memset(tong,0,sizeof(tong));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			int maxshu=max(a[i][1],max(a[i][2],a[i][3]));
			mark[i]=(maxshu==a[i][1]?1:(maxshu==a[i][2]?2:3));
			tong[(maxshu==a[i][1]?1:(maxshu==a[i][2]?2:3))]++;
		}
		int max_tong=max(tong[1],max(tong[2],tong[3]));
		int maxtb=(max_tong==tong[1]?1:(max_tong==tong[2]?2:3));
		int chao=maxtb-n/2;
		if(maxtb==1&&chao>n/2)
		{
			int a_[N]={0};
			for(int i=1;i<=n;i++)
				a_[i]=a[i][1];
			sort(a_+1,a_+1+n,cmp);
			for(int i=n/2+1;i<=n/2+chao;i++)
			{
				int w=0;
				for(int j=1;j<=n;j++)
					if(a_[i]==a[j][1])
					{
						w=j;
						break;
					}
				ans=ans-a_[i]+max(a[w][2],a[w][3]);
			}
		}
		else if(maxtb==2&&chao>n/2)
		{
			int a_[N]={0};
			for(int i=1;i<=n;i++)
				a_[i]=a[i][2];
			sort(a_+1,a_+1+n,cmp);
			for(int i=n/2+1;i<=n/2+chao;i++)
			{
				int w=0;
				for(int j=1;j<=n;j++)
					if(a_[i]==a[j][2])
					{
						w=j;
						break;
					}
				ans=ans-a_[i]+max(a[w][1],a[w][3]);
			}
		}
		else if(maxtb==3&&chao>n/2)
		{
			int a_[N]={0};
			for(int i=1;i<=n;i++)
				a_[i]=a[i][3];
			sort(a_+1,a_+1+n,cmp);
			for(int i=n/2+1;i<=n/2+chao;i++)
			{
				int w=0;
				for(int j=1;j<=n;j++)
					if(a_[i]==a[j][3])
					{
						w=j;
						break;
					}
				ans=ans-a_[i]+max(a[w][1],a[w][2]);
			}
		}
		for(int i=1;i<=n;i++)
			ans+=a[i][mark[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
