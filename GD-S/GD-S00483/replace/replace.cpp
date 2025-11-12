#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e6+9,K=12;
const ll base=19260817,mod=1e9+7;
ll n,Q;
char s1[N],s2[N];
char t1[N],t2[N];

unordered_map<ll,ll>mp[841];
set<ll>S[841];
ll pw[N];
void init()
{
	pw[0]=1;
	for(int i=1;i<N;i++)
	pw[i]=pw[i-1]*base%mod;
}
ll getHash(ll *ha,ll l,ll r)
{
	if(l>r)return 0;
	return (ha[r]-pw[r-l+1]*ha[l-1]%mod+mod)%mod;
}
ll h1[N],h2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		ll m=strlen(s1+1);
		ll x=s1[1]-'a'+1,y=s2[1]-'a'+1;
		ll ha1=0,ha2=0;
		for(int j=1;j<=m;j++)
		{
			ha1=(ha1*base%mod+(s1[j]-'a'+1))%mod;
			ha2=(ha2*base%mod+(s2[j]-'a'+1))%mod;
		}
		ll mg=(ha1*pw[m]%mod+ha2)%mod;
		mp[x*26+y][mg]++;
		S[x*26+y].insert(m);
	}
	while(Q--)
	{
		scanf("%s%s",t1+1,t2+1);
		if(strlen(t1+1)!=strlen(t2+1))
		{
			puts("0");
			continue;
		}
		ll m=strlen(t1+1),ret=0;
		bool spc=0;
		for(int i=1;i<=m;i++)
		{
			h1[i]=(h1[i-1]*base%mod+(t1[i]-'a'+1))%mod;
			h2[i]=(h2[i-1]*base%mod+(t2[i]-'a'+1))%mod;
		}
		ll H1=h1[m],H2=h2[m];
		for(int i=1;i<=m;i++)
		{
			ll x=t1[i]-'a'+1,y=t2[i]-'a'+1;
			ll b=x*26+y;
			auto it=S[b].rbegin();
			for(;it!=S[b].rend();it++)
			{
				ll len=(*it);
				if(i+len-1>m)continue;
				ll mg=(getHash(h1,i,i+len-1)*pw[len]%mod+getHash(h2,i,i+len-1))%mod;
				if((getHash(h1,1,i-1)*base%mod+getHash(h1,i+len,m))%mod==(getHash(h2,1,i-1)*base%mod+getHash(h2,i+len,m))%mod)
				{
					ret+=mp[b][mg];
				}
				else break;
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
