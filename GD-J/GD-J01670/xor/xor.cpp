#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=5e5+10;
string st;
ll a[MaxN],w,n,k,f[MaxN],kx,ans,s[1500000][2];
struct CSpj
{
	ll x,y;
}b[MaxN];

struct CSps
{
	ll xl,yl;
}c[MaxN];
ll cmp(CSps xx,CSps yy)
{
	if(xx.yl==yy.yl) return xx.xl<yy.xl;
	return xx.yl<yy.yl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	s[k][0]=0,s[k][1]=1;
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		s[f[i]^k][0]=i,s[k^f[i]][1]=1;
		if(s[f[i]][1]==1)
		{
			b[++w].x=s[f[i]][0]+1;
			b[w].y=i;
		}
		if(a[i]==k)
		{
			b[++w].x=i;
			b[w].y=i;
		}
	}
	ll r=0;
	for(ll i=1; i<=w; i++)
	{
		if(b[i].x<=b[i].y)
		{
			c[++kx].xl=b[i].x,c[kx].yl=b[i].y;
		} 
	}
	sort(c+1,c+1+kx,cmp);
	for(ll i=1; i<=kx; i++)
	{
		if(c[i].xl>r)
		{
			ans++;
			r=c[i].yl;	
		}	
	}
	cout<<ans;
	return 0;
}
