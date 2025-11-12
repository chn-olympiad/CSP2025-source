#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,cnt[3],mx,ans,m,b[N];
struct _
{
	int v[3],x,mx;
}a[N];
void solve()
{
	cnt[0]=cnt[1]=cnt[2]=mx=ans=m=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
		a[i].mx=max(a[i].v[0],max(a[i].v[1],a[i].v[2]));
		if(a[i].v[0]==a[i].mx)
		{
			a[i].x=0;
			cnt[0]++;
			ans+=a[i].v[0];
		}
		else if(a[i].v[1]==a[i].mx)
		{
			a[i].x=1;
			cnt[1]++;
			ans+=a[i].v[1];
		}
		else
		{
			a[i].x=2;
			cnt[2]++;
			ans+=a[i].v[2];
		}
	}
	mx=max(cnt[0],max(cnt[1],cnt[2]));
	if(mx<=n/2)
	{
		cout<<ans<<'\n';
		return;
	}
	if(mx==cnt[0]) mx=0;
	else if(mx==cnt[1]) mx=1;
	else mx=2;
	for(int i=1;i<=n;++i)
	{
		if(a[i].x==mx)
		{
			if(mx==0) b[++m]=max(a[i].v[1]-a[i].mx,a[i].v[2]-a[i].mx);
			else if(mx==1) b[++m]=max(a[i].v[0]-a[i].mx,a[i].v[2]-a[i].mx);
			else b[++m]=max(a[i].v[1]-a[i].mx,a[i].v[0]-a[i].mx);
		}
	}
	sort(b+1,b+m+1);
	for(int i=m;i>n/2;--i) ans+=b[i];
	cout<<ans<<'\n';
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin>>t;t;--t) solve();
	return 0;
}