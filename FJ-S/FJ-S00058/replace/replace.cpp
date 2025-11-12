#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=2e5+5,L=5e6+5;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3f;
const ULL mod=38888888888888839ULL,base=3889ULL;//«‡Õ‹»˝∞À∞À[∞›–ª][∞›–ª][∞›–ª] 
int n,q,tr[2][L][26],cnt[2]={0,0},vis[N];
unordered_map<int,vector<int> >mp[2];
unordered_map<ULL,int>mm[2];
void ins(int id,string s,int ln,int l,int r,ULL h)
{
	int p=0;
	if(!mm[0][h])
		mm[0][h]=++cnt[0];
	p=mm[0][h];
	for(int i=l;i;i--)
	{
		int u=s[i]-'a';
		if(!tr[0][p][u])
			tr[0][p][u]=++cnt[0];
		p=tr[0][p][u];
	}
	mp[0][p].push_back(id);
	if(!mm[1][h])
		mm[1][h]=++cnt[1];
	p=mm[1][h];
	for(int i=r;i<=ln;i++)
	{
		int u=s[i]-'a';
		if(!tr[1][p][u])
			tr[1][p][u]=++cnt[1];
		p=tr[1][p][u];
	}
	mp[1][p].push_back(id);
}
int fnd(int id,string s,int ln,int l,int r,ULL h)
{
	int p=mm[0][h],res=0;
	if(!p)
		return 0;
	for(int i=l;i&&p;i--)
	{
		for(int j:mp[0][p])
			vis[j]=id;
		int u=s[i]-'a';
		p=tr[0][p][u];
	}
	if(p)
		for(int j:mp[0][p])
			vis[j]=id;
	p=mm[1][h];
	for(int i=r;i<=ln&&p;i++)
	{
		for(int j:mp[1][p])
			if(vis[j]==id)
				res++;
		int u=s[i]-'a';
		p=tr[1][p][u];
	}
	if(p)
		for(int j:mp[1][p])
			if(vis[j]==id)
				res++;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s0,s1;
		cin>>s0>>s1;
		if(s0==s1)
			continue;
		int ln=s0.size(),l=0,r=ln+1;
		s0=' '+s0;
		s1=' '+s1;
		while(l<ln&&s0[l+1]==s1[l+1])
			l++;
		while(r>1&&s0[r-1]==s1[r-1])
			r--;
		ULL hh=0;
		for(int j=l+1;j<r;j++)
			hh=(hh*base%mod+s0[j])%mod;
		for(int j=l+1;j<r;j++)
			hh=(hh*base%mod+s1[j])%mod;
		ins(i,s0,ln,l,r,hh);
	}
	for(int i=1;i<=q;i++)
	{
		string t0,t1;
		cin>>t0>>t1;
		int ln=t0.size(),l=0,r=ln+1;
		t0=' '+t0;
		t1=' '+t1;
		while(l<ln&&t0[l+1]==t1[l+1])
			l++;
		while(r>1&&t0[r-1]==t1[r-1])
			r--;
		ULL hh=0;
		for(int j=l+1;j<r;j++)
			hh=(hh*base%mod+t0[j])%mod;
		for(int j=l+1;j<r;j++)
			hh=(hh*base%mod+t1[j])%mod;
		cout<<fnd(i,t0,ln,l,r,hh)<<'\n';
	}
	return 0;
}
//meow?
