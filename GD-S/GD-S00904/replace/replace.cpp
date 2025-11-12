#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll M=5000010,B=131,mod=1e9+7;
ll n,q,lx,ly,l,r,s;ll a[M],b[M],p[M],xx,yy;multimap<ll,ll> m[M];string x,y;
ll pd(string x)
{
	ll l=x.size();ll t=0;
	for(register ll i=0;i<l;++i)
		t=(t*B+x[i])%mod;
	return t;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(register ll i=1;i<=n;++i)
	{
		cin>>x>>y;
//		m[x.size()][pd(x)]=pd(y);
		m[x.size()].insert({pd(x),pd(y)});
//		cout<<pd(x)<<' '<<pd(y)<<'\n';
	}
	while(q--)
	{
		cin>>x>>y;
		lx=x.size(),ly=y.size();
		if(lx!=ly){cout<<"0\n";continue;}
		x=" "+x,y=" "+y;
		for(register ll i=1;i<=lx;++i)
			a[i]=(a[i-1]*B+x[i])%mod; 
		for(register ll i=1;i<=ly;++i)
			b[i]=(b[i-1]*B+y[i])%mod;
		p[0]=1;
		for(register ll i=1;i<=lx;++i)
			p[i]=p[i-1]*B%mod;
		l=n+1,r=0;s=0;
		for(register ll i=1;i<=lx;++i)
			if(x[i]!=y[i]){l=i;break;}
		for(register ll i=lx;i>=l;--i)
			if(x[i]!=y[i]){r=i;break;}
		for(register ll sz=r-l+1;sz<=lx;++sz)
		{
			if(m[sz].empty())continue;
			for(ll i=max(1ll,r-sz+1),j=i+sz-1;i<=l&&j<=lx;++i,++j)
			{
//				cout<<i<<' '<<j<<'\n';
				xx=((a[j]-a[i-1]*p[j-i+1]%mod)%mod+mod)%mod;
//				cout<<a[i-1]<<' '<<a[j]<<' '<<p[j-i+1]<<' '<<xx<<'\n';
				if(!m[sz].count(xx))continue;
				yy=((b[j]-b[i-1]*p[j-i+1]%mod)%mod+mod)%mod;
//				if(m[sz][xx]==yy)++s;
				std::multimap<ll,ll>::iterator it=m[sz].find(xx);
				for(;it!=m[sz].end();++it)
				{
					if((it->first)!=xx)break;
					else if((it->second)==yy)++s; 
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
