#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct data
{
	int bh,c,nxt;
	friend bool operator < (data a,data b){return a.c<b.c;}
}s[N];
int t,n,limit,a[N],b[N],c[N],f[N],sa,sb,sc,ans,k,nxt,sum;
bool vis[N][4];
void solve()
{
	scanf("%d",&n);
	limit=n/2;
	memset(vis,0,sizeof vis);
	ans=sa=sb=sc=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]>=b[i]&&a[i]>=c[i]) sa++,ans+=a[i],f[i]=1,vis[i][1]=1;
		else if(b[i]>=a[i]&&b[i]>=c[i]) sb++,ans+=b[i],f[i]=2,vis[i][2]=1;
		else sc++,ans+=c[i],f[i]=3,vis[i][3]=1;
	}
	while(sa>limit||sb>limit||sc>limit)
	{
		if(sa>limit)
		{
			k=0;
			for(int i=1;i<=n;i++) if(f[i]==1)
			{
				if(vis[i][2]) nxt=3,sum=c[i];
				else if(vis[i][3]) nxt=2,sum=b[i];
				else
				{
					if(b[i]>=c[i]) nxt=2,sum=b[i];
					else nxt=3,sum=c[i];
				}
				s[++k]={i,a[i]-sum,nxt};
			}
			sort(s+1,s+1+k);
			for(int i=1;i<=sa-limit;i++)
			{
				f[s[i].bh]=s[i].nxt,vis[s[i].bh][s[i].nxt]=1;
				ans-=s[i].c,sa--;
				if(s[i].nxt==2) sb++;
				else sc++;
			}
		}
		if(sb>limit)
		{
			k=0;
			for(int i=1;i<=n;i++) if(f[i]==2)
			{
				if(vis[i][1]) nxt=3,sum=c[i];
				else if(vis[i][3]) nxt=1,sum=a[i];
				else
				{
					if(a[i]>=c[i]) nxt=1,sum=a[i];
					else nxt=3,sum=c[i];
				}
				s[++k]={i,b[i]-sum,nxt};
			}
			sort(s+1,s+1+k);
			for(int i=1;i<=sb-limit;i++)
			{
				f[s[i].bh]=s[i].nxt,vis[s[i].bh][s[i].nxt]=1;
				ans-=s[i].c,sb--;
				if(s[i].nxt==1) sa++;
				else sc++;
			}
		}
		if(sc>limit)
		{
			k=0;
			for(int i=1;i<=n;i++) if(f[i]==3)
			{
				if(vis[i][1]) nxt=2,sum=b[i];
				else if(vis[i][2]) nxt=1,sum=a[i];
				else
				{
					if(a[i]>=b[i]) nxt=1,sum=a[i];
					else nxt=2,sum=b[i];
				}
				s[++k]={i,c[i]-sum,nxt};
			}
			sort(s+1,s+1+k);
			for(int i=1;i<=sc-limit;i++)
			{
				f[s[i].bh]=s[i].nxt,vis[s[i].bh][s[i].nxt]=1;
				ans-=s[i].c,sc--;
				if(s[i].nxt==1) sa++;
				else sb++;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
