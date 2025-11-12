#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244853;
const int base=200;
map<pair<pair<int,int>,int>,int> mp;
int cnt=0;
vector<int> v[200010];
unordered_map<int,int> now;
int qp[200010];
int gethash(string s)
{
	int ret=0;
	for(int i=0;i<s.size();i++) ret=ret*base+s[i]-'a'+1,ret%=mod;
	return ret;
}
void geterase(string s1,string s2,string &t1,string &t2,string &fr,string &bk)
{
	int l,r;
	for(int i=0;i<s1.size();i++) if(s1[i]!=s2[i])
	{
		l=i;
		break;
	}
	for(int i=s1.size()-1;~i;i--) if(s1[i]!=s2[i])
	{
		r=i;
		break;
	}
	t1=s1.substr(l,r-l+1);
	t2=s2.substr(l,r-l+1);
	fr=s1.substr(0,l);
	bk=s1.substr(r+1,s1.size()-1-r);
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,q;
	qp[0]=1;
	cin>>n>>q;
	for(int i=1;i<=n;i++) qp[i]=qp[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		string s1,s2,t1,t2,fr,bk;
		cin>>s1>>s2;
		if(s1==s2) continue;
		geterase(s1,s2,t1,t2,fr,bk);
//		cout<<"!:"<<t1<<','<<t2<<','<<fr<<','<<bk<<'\n'; 
		int h1=gethash(t1),h2=gethash(t2),hf=gethash(fr),hb=gethash(bk);
		if(!mp[{{h1,h2},hf}]) mp[{{h1,h2},hf}]=++cnt;
		v[mp[{{h1,h2},hf}]].push_back(hb);
	}
	while(q--)
	{
		string s1,s2,t1,t2,fr,bk;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		unordered_map<int,int> ().swap(now);
		geterase(s1,s2,t1,t2,fr,bk);
		int hf=gethash(fr),h1=gethash(t1),h2=gethash(t2);
		for(int i=0;i<fr.size();i++)
		{
			int nv=mp[{{h1,h2},hf}];
			for(auto j:v[nv]) now[j]++;
			hf-=qp[fr.size()-i-1]*(fr[i]-'a'+1)%mod;
			hf=(hf+mod)%mod;
		}
		int nv=mp[{{h1,h2},0}];
		for(auto j:v[nv]) now[j]++;
		int nhb=0,ans=0;
		for(int i=0;i<bk.size();i++)
		{
			ans+=now[nhb];
			nhb=nhb*base+(bk[i]-'a'+1);
			nhb%=mod;
		}
		ans+=now[nhb];
		cout<<ans<<'\n';
	}
}
