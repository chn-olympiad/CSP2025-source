#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=100005;
int a[N][3],t[N],cnt[3],p[N],k,n;
ll ans;
void solve()
{
	cin>>n;
	memset(cnt,0,sizeof cnt),ans=0;
	for(int i=1;i<=n;++i)
		cin>>a[i][0]>>a[i][1]>>a[i][2],t[i]=max_element(a[i],a[i]+3)-a[i],++cnt[t[i]],ans+=a[i][t[i]];
	if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
	{
		cout<<ans<<'\n';
		return;
	}
	int u=max_element(cnt,cnt+3)-cnt,v=0,w=1;
	if(u==0)
		v=1,w=2;
	else if(u==1)
		w=2;
	k=0;
	for(int i=1;i<=n;++i)
		if(t[i]==u)
			p[++k]=a[i][t[i]]-max(a[i][v],a[i][w]);
	sort(p+1,p+1+k);
	for(int i=1;i<=cnt[u]-n/2;++i)
		ans-=p[i];
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
