#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ul unsigned long long
ll n,q;
ul sde1=6873749283092938151,sde2=3728738475987204755;
ul bse=131;
string s1[200000+5],s2[200000+5];
ll len[200000+5];
ll dl[200000+5],dr[200000+5];
struct node
{
	int nxt[26],cnt,mk;
} tr1[5200000+5],tr2[5200000+5];
struct nd
{
	ll id;
	ul v;
} tmp[200000+5];
bool cmp(nd x,nd y)
{
	return x.v<y.v;
}
map<ul,ll> mp;
node *b1[200000+5];
node *b2[200000+5];
ll cnt1[200000+5],cnt2[200000+5];
ll ins1(node *tr,ll &tot,string &s,ll x)
{
	ll nw=0;
	tr[0].cnt++;
	for(ll i=x;i>=1;i--)
	{
		if(!tr[nw].nxt[s[i]-'a']) tr[nw].nxt[s[i]-'a']=++tot;
		nw=tr[nw].nxt[s[i]-'a'];
		tr[nw].cnt++;
	}
	return nw;
}
ll ins2(node *tr,ll &tot,string &s,ll x)
{
	ll nw=0;
	tr[0].cnt++;
	ll len=(ll)s.size()-1;
	for(ll i=x;i<=len;i++)
	{
		if(!tr[nw].nxt[s[i]-'a']) tr[nw].nxt[s[i]-'a']=++tot;
		nw=tr[nw].nxt[s[i]-'a'];
		tr[nw].cnt++;
	}
	return nw;
}
void cha1(node *tr,string &s,ll x)
{
	ll nw=0;
	tr[0].mk=1;
	for(ll i=x;i>=1;i--)
	{
		if(!tr[nw].nxt[s[i]-'a']) return;
		nw=tr[nw].nxt[s[i]-'a'];
		tr[nw].mk=1;
	}
//	cout<<nw<<"\n";
}
void cha2(node *tr,string &s,ll x)
{
	ll len=(ll)s.size()-1;
	ll nw=0;
	tr[0].mk=1;
	for(ll i=x;i<=len;i++)
	{
		if(!tr[nw].nxt[s[i]-'a']) return;
		nw=tr[nw].nxt[s[i]-'a'];
		tr[nw].mk=1;
	}
//	cout<<nw<<"#\n"; 
}
ll ksl[200000+5],ksr[200000+5];
ll pyl[200000+5],pyr[200000+5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	ll c=0;
	for(ll i=1;i<=n;i++)
	{
		string p1,p2;
		cin>>p1>>p2;
		if(p1==p2) continue;
		++c;
		s1[c]=p1,s2[c]=p2;
		len[c]=s1[c].size();
		s1[c]=' '+s1[c];
		s2[c]=' '+s2[c];
		ll pl=1,pr=len[c];
		for(ll j=1;j<=len[c];j++)
		{
			if(s1[c][j]==s2[c][j]) pl=j+1;
			else break;
		}
		for(ll j=len[c];j>=1;j--)
		{
			if(s1[c][j]==s2[c][j]) pr=j-1;
			else break;
		}
		dl[c]=pl,dr[c]=pr;
		tmp[c].id=c;
		ul f1=0,f2=0;
		for(ll j=pl;j<=pr;j++)
		{
			f1=f1*bse+(ul)(s1[c][j]-'a');
			f2=f2*bse+(ul)(s2[c][j]-'a');
		}
		tmp[c].v=f1*sde1+f2*sde2;
//		cout<<tmp[c].v<<' '<<pl<<' '<<pr<<"#\n";
	}
	n=c;
	sort(tmp+1,tmp+n+1,cmp);
	ll smn=0,pfm=0;
	for(ll i=1;i<=n;i++)
	{
		if(i==1||tmp[i].v!=tmp[i-1].v)
		{
			smn++,pfm++;
			b1[pfm]=&tr1[smn];
			b2[pfm]=&tr2[smn];
			mp[tmp[i].v]=pfm;
		}
		smn+=dr[tmp[i].id]-dl[tmp[i].id]+1;
	}
	for(ll i=1;i<=n;i++)
	{
		ll ts=mp[tmp[i].v];
		if(i==1||tmp[i].v!=tmp[i-1].v) ksl[ts]=i;
		if(i==n||tmp[i].v!=tmp[i+1].v) ksr[ts]=i;
		pyl[i]=ins1(b1[ts],cnt1[ts],s1[tmp[i].id],dl[tmp[i].id]-1);
//		ins1(b2[ts],cnt2[ts],s2[tmp[i].id],dl[tmp[i].id]-1);
		pyr[i]=ins2(b2[ts],cnt2[ts],s1[tmp[i].id],dr[tmp[i].id]+1);
//		ins2(b2[ts],cnt2[ts],s2[tmp[i].id],dr[tmp[i].id]+1);
	}
	while(q--)
	{
		string u1,u2;
		cin>>u1>>u2;
		if(u1.size()!=u2.size())
		{
			cout<<"0\n";
			continue;
		}
		ll pln=u1.size();
		u1=' '+u1,u2=' '+u2;
		ll pl=1,pr=pln;
		for(ll j=1;j<=pln;j++)
		{
			if(u1[j]==u2[j]) pl=j+1;
			else break;
		}
		for(ll j=pln;j>=1;j--)
		{
			if(u1[j]==u2[j]) pr=j-1;
			else break;
		}
		ul f1=0,f2=0;
		for(ll j=pl;j<=pr;j++)
		{
			f1=f1*bse+(ul)(u1[j]-'a');
			f2=f2*bse+(ul)(u2[j]-'a');
		}
		ul pmrd=f1*sde1+f2*sde2;
		if(!mp.count(pmrd))
		{
			cout<<"0\n";
			continue;
		}
		ll ans=0;
		ll ds=mp[pmrd];
		for(ll j=0;j<=cnt1[ds];j++) b1[ds][j].mk=0;
		for(ll j=0;j<=cnt2[ds];j++) b2[ds][j].mk=0;
		cha1(b1[ds],u1,pl-1);
		cha2(b2[ds],u1,pr+1);
//		cout<<
		for(ll j=ksl[ds];j<=ksr[ds];j++)
		{
//			cout<<j<<' '<<pyl[j]<<' '<<pyr[j]<<"#\n";
			if(b1[ds][pyl[j]].mk&&b2[ds][pyr[j]].mk) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
这个范围再阴间点吧。。。/tuu/tuu/tuu 
*/
