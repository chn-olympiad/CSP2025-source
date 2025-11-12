#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const ll MAXN=2e5+5,MAXL=5e6+5,MOD[2]={998244353,1000000007};
struct node
{
	ll hash[3][2]={};
	node(){}
	node(ll h10,ll h11,ll h20,ll h21)
	{
		hash[1][0]=h10,hash[1][1]=h11,
		hash[2][0]=h20,hash[2][1]=h21;
	}
}Hash[MAXN],h[MAXL];
ll n,q,Pow26[MAXL][2],Len[MAXN];
char s[3][MAXL],t[3][MAXL];
ll getHash(ll L,ll R,ll p,ll q)
{
	return (h[R].hash[p][q]-h[L-1].hash[p][q]*Pow26[R-L+1][q]%MOD[q]+MOD[q])%MOD[q];
}
bool special=true;
class SUBB
{
	private:
		ll pos[MAXN][3];
		map<ll,vector<pair<ll,ll>>> shift;
	public:
		bool check(ll d)
		{
			for(ll i=1;i<=Len[d];i++)
			{
				if(s[1][i]!='a'&&s[1][i]!='b'||s[2][i]!='a'&&s[2][i]!='b')
					return false;
				if(s[1][i]=='b') pos[d][1]=i;
				if(s[2][i]=='b') pos[d][2]=i;
			}
			return true;
		}
		void work()
		{
			for(ll i=1;i<=n;i++) shift[pos[i][2]-pos[i][1]].pb(mp(pos[i][1],Len[i]-pos[i][1]));
			for(ll i=1;i<=q;i++)
			{
				scanf("%s%s",t[1]+1,t[2]+1);
				ll len=strlen(t[1]+1),pos[3],ans=0;
				for(ll i=1;i<=len;i++)
				{
					if(t[1][i]=='b') pos[1]=i;
					if(t[2][i]=='b') pos[2]=i;
				}
				for(auto u:shift[pos[2]-pos[1]])
					if(pos[1]>=u.first&&len-pos[1]>=u.second) ans++;
				printf("%lld\n",ans);
			}
		}
}subB;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Pow26[0][0]=Pow26[0][1]=1;
	for(ll i=1;i<=5e6;i++)
	{
		Pow26[i][0]=Pow26[i-1][0]*26%MOD[0];
		Pow26[i][1]=Pow26[i-1][1]*26%MOD[1];
	}
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++)
	{
		scanf("%s%s",s[1]+1,s[2]+1);
		Len[i]=strlen(s[1]+1);
		for(ll j=1;j<=Len[i];j++)
		{
			Hash[i].hash[1][0]=(Hash[i].hash[1][0]*26+(s[1][j]-'a'))%MOD[0];
			Hash[i].hash[1][1]=(Hash[i].hash[1][1]*26+(s[1][j]-'a'))%MOD[1];
			Hash[i].hash[2][0]=(Hash[i].hash[2][0]*26+(s[2][j]-'a'))%MOD[0];
			Hash[i].hash[2][1]=(Hash[i].hash[2][1]*26+(s[2][j]-'a'))%MOD[1];
		}
		special&=subB.check(i);
	}
	if(special)
	{
		subB.work();
		return 0;
	}
	for(ll i=1;i<=q;i++)
	{
		scanf("%s%s",t[1]+1,t[2]+1);
		ll len=strlen(t[1]+1),L=len,R=1;
		for(ll j=1;j<=len;j++)
		{
			h[j].hash[1][0]=(h[j-1].hash[1][0]*26+(t[1][j]-'a'))%MOD[0];
			h[j].hash[1][1]=(h[j-1].hash[1][1]*26+(t[1][j]-'a'))%MOD[1];
			h[j].hash[2][0]=(h[j-1].hash[2][0]*26+(t[2][j]-'a'))%MOD[0];
			h[j].hash[2][1]=(h[j-1].hash[2][1]*26+(t[2][j]-'a'))%MOD[1];
			if(t[1][j]!=t[2][j]) L=min(L,j),R=max(R,j);
		}
		ll ans=0;
		for(ll j=1;j<=n;j++)
			for(ll k=max(R-Len[j]+1,1LL);k<=min(L,len-Len[j]+1);k++)
				if(getHash(k,k+Len[j]-1,1,0)==Hash[j].hash[1][0]
				 &&getHash(k,k+Len[j]-1,1,1)==Hash[j].hash[1][1]
				 &&getHash(k,k+Len[j]-1,2,0)==Hash[j].hash[2][0]
				 &&getHash(k,k+Len[j]-1,2,1)==Hash[j].hash[2][1]) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
