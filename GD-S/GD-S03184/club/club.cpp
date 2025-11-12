#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,T;
struct node{
	ll x,y,z;
	ll bh;
}a[N];
ll ans,js[4];
bool vis[N];
bool cmp(node n1,node n2)
{
	if(n1.x==n2.x) return n1.y<n2.y;
	return n1.x>n2.x;
}
bool cmp2(node n1,node n2)
{
	return n1.y>n2.y;
}
bool cmp3(node n1,node n2)
{
	return n1.z>n2.z;
}
void solve()
{
sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=n;i++)
		{
			if(js[1]*2==n) break;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				js[1]++;
				vis[a[i].bh]=true;
				ans+=a[i].x;
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(ll i=1;i<=n;i++)
		{
			
			if(js[2]*2==n) break;
			if(vis[a[i].bh]) continue;
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				js[2]++;
				vis[a[i].bh]=true;
				ans+=a[i].y;
				
			}			
		}
		sort(a+1,a+1+n,cmp3);
		for(ll i=1;i<=n;i++)
		{
			if(js[3]*2==n) break;
			if(vis[a[i].bh]) continue;
			if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
			{
				js[3]++;
				vis[a[i].bh]=true;
				ans+=a[i].z;
				
			}			
		}
		
		
		sort(a+1,a+1+n,cmp);
		for(ll i=1;i<=n;i++)
		{
			if(js[1]*2==n) break;
			if(vis[a[i].bh]) continue;
			if(a[i].x>=a[i].y||a[i].x>=a[i].z)
			{
				js[1]++;
				vis[a[i].bh]=true;
				ans+=a[i].x;
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(ll i=1;i<=n;i++)
		{
			if(js[2]*2==n) break;
			if(vis[a[i].bh]) continue;
			if(a[i].y>=a[i].x||a[i].y>=a[i].z)
			{
				js[2]++;
				vis[a[i].bh]=true;
				ans+=a[i].y;
			}			
		}
		sort(a+1,a+1+n,cmp3);
		for(ll i=1;i<=n;i++)
		{
			if(js[3]*2==n) break;
			if(vis[a[i].bh]) continue;
			if(a[i].z>=a[i].x||a[i].z>=a[i].y)
			{
				js[3]++;
				vis[a[i].bh]=true;
				ans+=a[i].z;
			}
		}
		
		sort(a+1,a+1+n,cmp);
		for(ll i=1;i<=n;i++)
		{
			if(js[1]*2==n) break;
			if(vis[a[i].bh]) continue;
			js[1]++;
			vis[a[i].bh]=true;
			ans+=a[i].x;
		}
		sort(a+1,a+1+n,cmp2);
		for(ll i=1;i<=n;i++)
		{
			if(js[2]*2==n) break;
			if(vis[a[i].bh]) continue;
			js[2]++;
			vis[a[i].bh]=true;
			ans+=a[i].y;			
		}
		sort(a+1,a+1+n,cmp3);
		for(ll i=1;i<=n;i++)
		{
			if(js[3]*2==n) break;
			if(vis[a[i].bh]) continue;
			js[3]++;
			vis[a[i].bh]=true;
			ans+=a[i].z;
		}
		
		printf("%lld\n",ans);	
}

ll dans;
void dfs(ll x,ll da,ll db,ll dc,ll s)
{
	if(x>n)
	{
		dans=max(dans,s);
		return;
	}
	if(da*2<n)
	dfs(x+1,da+1,db,dc,s+a[x].x);
	if(db*2<n)
	dfs(x+1,da,db+1,dc,s+a[x].y);
	if(dc*2<n)
	dfs(x+1,da,db,dc+1,s+a[x].z);
	return;
}
void solve3()
{
	dans=0;
	dfs(1,0,0,0,0);
	printf("%lld\n",dans);
}
void solveA()
{
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<=n/2;i++)
	  ans+=a[i].x;
	printf("%lld\n",ans);
}
ll tr[N];
void solveB()
{
	sort(a+1,a+n+1,cmp);
	
	for(ll i=1;i<=n/2;i++)
	{
		for(ll j=n/2+1;j<=n;j++)
		if(a[i].x+a[j].y<a[i].y+a[j].x)
		{
			swap(a[i],a[j]);
			i=1;
		}
	}
	for(ll i=1;i<=n/2;i++)
	 ans+=a[i].x+a[n/2+i].y;
	printf("%lld\n",ans);
}
void solve2()
{
	
	
	for(ll i=1;i<=n/2;i++)
	{
		
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		memset(vis,false,sizeof(vis));
		ans=0;
		bool fA=true,fB=true;
		memset(js,0,sizeof(js));
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			a[i].bh=i;
			if(a[i].y!=0||a[i].z!=0) fA=false;
			if(a[i].z!=0) fB=false;
		}
		if(fA) solveA();
		else if(fB) solveB();
		else if(n<=30) solve3();
		else solve();
		
	}
	
	return 0;
}
