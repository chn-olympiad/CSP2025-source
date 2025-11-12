#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n;
struct jjj{int a1,a2,a3,maxn,fa,remax,minn,fa1;}a[N];
ll ans;
int cnt[4],f,c;
bool cmp(jjj a,jjj b){return a.maxn-a.remax<b.maxn-b.remax;}
bool cmp1(jjj a,jjj b){return a.remax-a.minn<b.remax-b.minn;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		f=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].maxn=max({a[i].a1,a[i].a2,a[i].a3});
			if(a[i].maxn==a[i].a1) ++cnt[1],a[i].fa=1;
			else if(a[i].maxn==a[i].a2) ++cnt[2],a[i].fa=2;
			else ++cnt[3],a[i].fa=3;
			a[i].remax=a[i].a1+a[i].a2+a[i].a3-max({a[i].a1,a[i].a2,a[i].a3})-min(a[i].a1,min(a[i].a2,a[i].a3));
			if(a[i].remax==a[i].a1&&a[i].fa!=1) a[i].fa1=1;
			else if(a[i].remax==a[i].a2&&a[i].fa!=2) a[i].fa1=2;
			else a[i].fa1=3;
			a[i].minn=a[i].a1+a[i].a2+a[i].a3-a[i].maxn-a[i].remax;
		}
		for(int i=1;i<=n;++i) ans+=a[i].maxn;
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		if(cnt[1]>n/2) f=1;
		else if(cnt[2]>n/2) f=2;
		else f=3;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i) 
			if(a[i].fa==f)
			{
				cnt[f]--,cnt[a[i].fa1]++,ans+=(a[i].remax-a[i].maxn),a[i].fa=a[i].fa1;
				if(cnt[f]<=n/2) break;
			}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){cout<<ans<<"\n";continue;}
		if(cnt[1]>n/2) f=1;
		else if(cnt[2]>n/2) f=2;
		else f=3;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;++i)
		{
			if(a[i].fa==f)
			{
				cnt[f]--;ans+=(a[i].minn-a[i].remax);
				if(cnt[f]<=n/2) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
