#include<bits/stdc++.h>
#define ll long long
#define y1 gndfg
#define pii pair<ll,ll>
using namespace std;
const int N=5e6+10,base1=13,base2=3,mod=1e9+7;
int n,q;
ll p1[N],f1[N],g1[N],inv1[N],p2[N],inv2[N],f2[N],g2[N];
set<int>s;
vector<int>v;
map<pair<ll,ll>,int>mp;
string read()
{
	char c=getchar();
	while(c==' '||c=='\n')c=getchar();
	string s="";
	while(!(c==' '||c=='\n'))s+=c,c=getchar();
	return s;
}
pii ask(string s)
{
	ll sum1=0,sum2=0;
	for(int i=1;i<=s.size();i++)
	{
		sum1+=p1[i]*(s[i-1]-'a'+1)%mod,sum1%=mod;
		sum2+=p2[i]*(s[i-1]-'a'+1)%mod,sum2%=mod;
	}
	return {sum1,sum2};
}
ll qpow(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y%2)ans*=x,ans%=mod;
		x*=x,x%=mod,y/=2;
	}
	return ans;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p1[0]=inv1[0]=1;
	p2[0]=inv2[0]=1;
	for(int i=1;i<N;i++)
	{
		p1[i]=p1[i-1]*base1%mod,inv1[i]=qpow(p1[i],mod-2);
		p2[i]=p2[i-1]*base2%mod,inv2[i]=qpow(p2[i],mod-2);
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string x=read(),y=read();
		s.insert(x.size());
		x+=y;
		mp[ask(x)]++;
	}
	for(int i:s)
		v.push_back(i);
	while(q--)
	{
		string x=read(),y=read();
		if(x.size()!=y.size())
		{
			puts("0");
			continue;
		}
		int n=x.size();
		int l=0,r=n-1;
		while(x[l]==y[l])
			l++;
		while(x[r]==y[r])
			r--;
		for(int i=1;i<=n;i++)
		{
			f1[i]=f1[i-1]+p1[i]*(x[i-1]-'a'+1)%mod,f1[i]%=mod;
			f2[i]=f2[i-1]+p2[i]*(x[i-1]-'a'+1)%mod,f2[i]%=mod;
			g1[i]=g1[i-1]+p1[i]*(y[i-1]-'a'+1)%mod,g1[i]%=mod;
			g2[i]=g2[i-1]+p2[i]*(y[i-1]-'a'+1)%mod,g2[i]%=mod;
		}
		l++,r++;
		ll ans=0;
		for(int i:v)
		{
			for(int j=max(r-i+1,1);j<=min(l,n-i+1);j++)
			{
//				cout<<j<<' '<<j+i-1<<endl;
				ll x1=f1[j+i-1]-f1[j-1]+mod,y1=g1[j+i-1]-g1[j-1]+mod;
				x1%=mod,y1%=mod;
				x1*=inv1[j-1],x1%=mod;
				y1*=inv1[j-1],y1%=mod;
				y1*=p1[i],y1%=mod;
				ll x2=f2[j+i-1]-f2[j-1]+mod,y2=g2[j+i-1]-g2[j-1]+mod;
				x2%=mod,y2%=mod;
				x2*=inv2[j-1],x2%=mod;
				y2*=inv2[j-1],y2%=mod;
				y2*=p2[i],y2%=mod;
				ans+=mp[{(x1+y1)%mod,(x2+y2)%mod}];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

