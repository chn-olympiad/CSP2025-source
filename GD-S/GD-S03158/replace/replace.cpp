#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define ppp pair<pll,pll>
#define fi first
#define se second
using namespace std;
const ll m1=1101532409,m2=1473763919;
const ll p1=29,p2=31,N=2e5+10,M=5e6+10;
map<ppp,ll> mp;
ppp s[N];
pll a[M],b[M];
ll pw1[M],pw2[M];
ll n,q;
void init()
{
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=5000000;i++)
		pw1[i]=pw1[i-1]*p1%m1,pw2[i]=pw2[i-1]*p2%m2;
}
ppp ask(const ll&l,const ll&r)
{
	ll v1=(a[r].fi-a[l-1].fi*pw1[r-l+1]%m1+m1)%m1;
	ll v2=(a[r].se-a[l-1].se*pw2[r-l+1]%m2+m2)%m2;
	ll v3=(b[r].fi-b[l-1].fi*pw1[r-l+1]%m1+m1)%m1;
	ll v4=(b[r].se-b[l-1].se*pw2[r-l+1]%m2+m2)%m2;
	return {{v1,v2},{v3,v4}};
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	init();
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		ll h11=0,h12=0,h21=0,h22=0;
		for(int j=0;j<s1.size();j++)
		{
			h11=(h11*p1+(s1[j]-'a'+1))%m1;
			h12=(h12*p2+(s1[j]-'a'+1))%m2;
		}
		for(int j=0;j<s2.size();j++)
		{
			h21=(h21*p1+(s2[j]-'a'+1))%m1;
			h22=(h22*p2+(s2[j]-'a'+1))%m2;
		}
		mp[{{h11,h12},{h21,h22}}]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=s1.size();j++)
		{
			a[j].fi=(a[j-1].fi*p1+(s1[j-1]-'a'+1))%m1;
			a[j].se=(a[j-1].se*p2+(s1[j-1]-'a'+1))%m2;
		}
		for(int j=1;j<=s2.size();j++)
		{
			b[j].fi=(b[j-1].fi*p1+(s2[j-1]-'a'+1))%m1;
			b[j].se=(b[j-1].se*p2+(s2[j-1]-'a'+1))%m2;
		}
		ll l=0,r=0,ans=0;
		for(int j=1;j<=s1.size();j++)
			if(s1[j-1]!=s2[j-1])
			{l=j; break;}
		for(int j=s2.size();j>=1;j--)
			if(s1[j-1]!=s2[j-1])
			{r=j; break;}
		for(int i=1;i<=l;i++)
			for(int j=r;j<=s1.size();j++)
				ans+=mp[ask(i,j)];
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
