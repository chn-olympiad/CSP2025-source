#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,ans;
ll n,sum[100005];
struct cs
{
	ll a,b,c;
}s[100005];
ll f[3],f2,f3;
bool cmp(cs x,cs y)
{
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	return x.c<y.c;
}
void dfs(ll k,ll su)
{
	if(f[1]>n/2||f[2]>n/2||f[3]>n/2)return;
	if(su+sum[n]-sum[k-1]<=ans)return;
	if(k>n)
	{
		ans=max(ans,su);
		return;
	}
	f[1]++;
	dfs(k+1,su+s[k].a);
	f[1]--;
	f[2]++;
	dfs(k+1,su+s[k].b);
	f[2]--;
	f[3]++;
	dfs(k+1,su+s[k].c);
	f[3]--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=INT_MIN;
		for(ll i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0)f2=1;
			if(s[i].c!=0)f3=1;
		}
		sort(s+1,s+1+n,cmp);
		for(ll i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+max(s[i].a,max(s[i].b,s[i].c));
		}
		if(!f2&&!f3)
		{
			cout<<sum[n]<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
