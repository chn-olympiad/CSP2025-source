#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,len,c[20],ans,cnt,f[10010],v[10010];
struct bian{
	ll x,y,w;
}a[1020200];
void add(ll x,ll y,ll w)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].w=w;
}
bool cmp(bian x,bian y)
{
	return x.w<y.w;
}
ll find(ll x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	else return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			ll x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
		}
		for(int i=1;i<=k;i++)
		{
			ll va;
			cin>>c[i];
			for(int j=1;j<=n;j++)
				cin>>va;
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			ll x=a[i].x,y=a[i].y,w=a[i].w;
			if(find(x)!=find(y))
			{	
				f[y]=f[x];
				ans+=w;
				cnt++;
				if(cnt==n-1)
					break;
			}
		}
	}
	if(k!=0)
	{
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			ll x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
		}
		for(int i=1;i<=k;i++)
		{
			ll va;
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>va;
				add(i+n,j,va+c[i]);
			}
		}
		ll cnt1=n-1;
		sort(a+1,a+len+1,cmp);
		for(int i=1;i<=len;i++)
		{
			ll x=a[i].x,y=a[i].y,w=a[i].w;
			if(find(x)!=find(y))
			{	
				if(x>n&&!v[x])
				{
					cnt1++;
					v[x]=1;
				}
				f[y]=f[x];
				ans+=w;
				cnt++;
				if(cnt==cnt1)
					break;
			}
		}
	}
	cout<<ans;
	return 0;
}