#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct member
{
	ll fi,se,th;
}a[100005];
ll T,n,zd,t[100005],f[100005];
bool cmp(member xx,member yy)
{
	ll mxx=max(xx.fi,max(xx.se,xx.th));
	ll myy=max(yy.fi,max(yy.se,yy.th));
	return mxx>myy;
}
void dfs(ll k,ll x,ll y,ll z,ll s)
{
	if(k==n+1)
	{
		zd=max(zd,s);
		return ;
	}
	if(s+(t[n]-t[k-2])<=zd) return ;
	if(x<n/2) dfs(k+1,x+1,y,z,s+a[k].fi);
	if(y<n/2) dfs(k+1,x,y+1,z,s+a[k].se);
	if(z<n/2) dfs(k+1,x,y,z+1,s+a[k].th);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		memset(t,0,sizeof(t));
		zd=0;
		cin >> n;
		ll zdy=INT_MIN,zdz=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].fi >> a[i].se >> a[i].th;
			zdy=max(zdy,a[i].se);
			zdz=max(zdz,a[i].th);
			t[i]=t[i-1]+max(a[i].fi,max(a[i].se,a[i].th));
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout << zd <<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if(zdy==0 && zdz==0)
		{
			for(int i=1;i<=n/2;i++) zd+=a[i].fi;
			cout << zd;
		}
		else
		{
			ll xj=0,yj=0,zj=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].fi>=a[i].se && a[i].fi>=a[i].th)
				{
					if(xj<n/2) zd+=a[i].fi;
					else
					{
						if(f[i-1]==1)
						{
							if(a[i-1].se>=a[i-1].th && yj<n/2) zd+=a[i-1].se+a[i].fi-a[i-1].fi;
							else zd+=a[i-1].th+a[i].fi-a[i-1].fi;
						}
						else if(f[i-1]==2)
						{
							if(a[i-1].fi>=a[i-1].th && xj<n/2) zd+=a[i-1].fi+a[i].fi-a[i-1].se;
							else zd+=a[i-1].th+a[i].fi-a[i-1].se;
						}
						else
						{
							if(a[i-1].se>=a[i-1].fi && zj<n/2) zd+=a[i-1].se+a[i].fi-a[i-1].th;
							else zd+=a[i-1].fi+a[i].fi-a[i-1].th;
						}
					}
				}
				else if(a[i].se>=a[i].fi && a[i].se>=a[i].th)
				{
					if(yj<n/2) zd+=a[i].se;
					else
					{
						if(f[i-1]==1)
						{
							if(a[i-1].se>=a[i-1].th && yj<n/2) zd+=a[i-1].se+a[i].se-a[i-1].fi;
							else zd+=a[i-1].th+a[i].se-a[i-1].fi;
						}
						else if(f[i-1]==2)
						{
							if(a[i-1].fi>=a[i-1].th && xj<n/2) zd+=a[i-1].fi+a[i].se-a[i-1].se;
							else zd+=a[i-1].th+a[i].se-a[i-1].se;
						}
						else
						{
							if(a[i-1].se>=a[i-1].fi && zj<n/2) zd+=a[i-1].se+a[i].se-a[i-1].th;
							else zd+=a[i-1].fi+a[i].se-a[i-1].th;
						}
					}
				}
				else
				{
					if(zj<n/2) zd+=a[i].th;
					else
					{
						if(f[i-1]==1)
						{
							if(a[i-1].se>=a[i-1].th && yj<n/2) zd+=a[i-1].se+a[i].th-a[i-1].fi;
							else zd+=a[i-1].th+a[i].th-a[i-1].fi;
						}
						else if(f[i-1]==2)
						{
							if(a[i-1].fi>=a[i-1].th && xj<n/2) zd+=a[i-1].fi+a[i].th-a[i-1].se;
							else zd+=a[i-1].th+a[i].th-a[i-1].se;
						}
						else
						{
							if(a[i-1].se>=a[i-1].fi && zj<n/2) zd+=a[i-1].se+a[i].th-a[i-1].th;
							else zd+=a[i-1].fi+a[i].th-a[i-1].th;
						}
					}
				}
			}
			cout << zd;
		}
		cout <<"\n";
	}
	
	return 0;
}
/*
Rp++ 
T1就不会了qwq
but写了个神秘碰分小代码 
*/
