#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
inline int read()
{
	ll s=0,p=1;
	char c=getchar();
	while(!(c>='0'&&c<='9'||c=='-')) c=getchar();
	if(c=='-') p=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+(c-'0'),c=getchar();
	return s*p; 
}
const ll MAXN=1e5+5;
ll T,n,a[MAXN][5],chs[MAXN],cnt[5],chg[MAXN],L;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		ll ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(ll i=1;i<=n;i++)
		{
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) chs[i]=1,cnt[1]++,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) chs[i]=2,cnt[2]++,ans+=a[i][2];
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) chs[i]=3,cnt[3]++,ans+=a[i][3];
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			printf("%lld\n",ans);
			continue;
		}
		ll now,t1,t2;
		if(cnt[1]>n/2) now=1,t1=2,t2=3;
		else if(cnt[2]>n/2) now=2,t1=1,t2=3;
		else if(cnt[3]>n/2) now=3,t1=1,t2=2;
		L=0;
		for(ll i=1;i<=n;i++)
			if(chs[i]==now) chg[++L]=min(a[i][now]-a[i][t1],a[i][now]-a[i][t2]);
		sort(chg+1,chg+L+1);
		for(ll i=1;i<=cnt[now]-n/2;i++) ans-=chg[i];
		printf("%lld\n",ans);
	}
	return 0;
}
