#include<bits/stdc++.h>
#define ll int
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
ll n,t;
ll xl,yl,zl;
bool f[N];
struct p{
	ll mx,my,mz;
	ll maxn,zn,c;
}a[N];
struct node{
	ll r,id;
};
node x[N],y[N],z[N];
bool cmp(node A,node B)
{
	return A.r<B.r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		xl=yl=zl=0;
		cin>>n;
		for(ll i=0;i<=n;i++)
		{
			f[i]=0;
		}
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].mx>>a[i].my>>a[i].mz;
			if(a[i].mx>=a[i].my&&a[i].mx>=a[i].mz) 
			{
				
				a[i].maxn=a[i].mx;
				if(a[i].my>=a[i].mz)
				{
					a[i].c=a[i].maxn-a[i].my;
					a[i].zn=a[i].my;
				} 
				else
				{
					a[i].c=a[i].maxn-a[i].mz;
					a[i].zn=a[i].mz;
				}
				x[++xl].id=i;
				x[xl].r=a[i].c;
			}
			else if(a[i].my>=a[i].mx&&a[i].my>=a[i].mz) 
			{
				a[i].maxn=a[i].my;
				if(a[i].mx>=a[i].mz)
				{
					a[i].c=a[i].maxn-a[i].mx;
					a[i].zn=a[i].mx;
				} 
				else
				{
					a[i].c=a[i].maxn-a[i].mz;
					a[i].zn=a[i].mz;
				}
				y[++yl].id=i;
				y[yl].r=a[i].c;
			}
			else if(a[i].mz>=a[i].mx&&a[i].mz>=a[i].my) 
			{
				a[i].maxn=a[i].mz;
				if(a[i].mx>=a[i].my)
				{
					a[i].c=a[i].maxn-a[i].mx;
					a[i].zn=a[i].mx;
				} 
				else
				{
					a[i].c=a[i].maxn-a[i].my;
					a[i].zn=a[i].my;
				}
				z[++zl].id=i;
				z[zl].r=a[i].c;
			}
		}
		if(xl>n/2)
		{
			ll e=xl-n/2;
			sort(x+1,x+xl+1,cmp);
			for(ll i=1;i<=e;i++)
			{
				f[x[i].id]=1;
			}
		}
		else if(yl>n/2)
		{
			ll e=yl-n/2;
			sort(y+1,y+yl+1,cmp);
			for(ll i=1;i<=e;i++)
			{
				f[y[i].id]=1;
			}
		}
		else if(zl>n/2)
		{
			ll e=zl-n/2;
			sort(z+1,z+zl+1,cmp);
			for(ll i=1;i<=e;i++)
			{
				f[z[i].id]=1;
			}
		}
		long long ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==0)
			{
				ans+=a[i].maxn;
			}
			else
			{
				ans+=a[i].zn;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
