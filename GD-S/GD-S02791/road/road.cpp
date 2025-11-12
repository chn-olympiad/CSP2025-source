#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,cnt=0,s[20500],f[20500],d[20500];
bool vis[20500];
struct node
{
	ll x,y,w;
}a[5000000];
ll find(ll x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
void join(ll x,ll y)
{
	ll xx=find(x),yy=find(y);
	if(xx!=yy)
	{
		f[xx]=yy;
	}
	return;
}
bool cmp(node q,node p)
{
	if(q.w==p.w)
	{
		if(q.x==p.x)
			return q.y<p.y;
		return q.x<p.x;
	}
	return q.w<=p.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		int a1,b1,c1;
		cin>>a1>>b1>>c1;
		cnt++;
		a[cnt].x=a1,a[cnt].y=b1,a[cnt].w=c1;
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>d[i+n];
		for(ll j=1;j<=n;j++)
		{
			cin>>s[j];
			cnt++;
			a[cnt].x=i+n,a[cnt].y=j,a[cnt].w=s[j]+d[i+n];
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(ll i=1;i<=n+k;i++) f[i]=i;
	ll sum=1,ans=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			if(a[i].x>n&&vis[a[i].x]!=0)
			{
				ans-=d[a[i].x];
			}
			else if(vis[a[i].x]==0&&a[i].x>n)
			{
				vis[a[i].x]=1;
				sum--;
			}
			if(a[i].y>n&&vis[a[i].y]!=0)
			{
				ans-=d[a[i].y];
			}
			else if(vis[a[i].y]==0&&a[i].y>n)
			{
				vis[a[i].y]=1;
				sum--;
			}
			sum++;
			ans+=a[i].w;
			join(a[i].x,a[i].y);
		}
		if(sum==n)
		{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

