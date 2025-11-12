#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ve vector<int>
#define mid ((l+r)>>1)
#define lx (x<<1)
#define rx (x<<1|1)
using namespace std;
const int N=5e5+2,M=6e6+2;
const ll P=1e16+61;
int n,m,k,d,cnt,tr[M],ans[N];
int rt[N],dfn[M],dfm[M],f[M][26];
pii c[N];
map<ll,int>mp;
struct node{int x,y,z,t;}mf[N];
void mdf(int x,int y){for(;x<=k;x+=x&-x)tr[x]+=y;}
int qry(int x,int y=0){for(;x;x-=x&-x)y+=tr[x];return y;}
ll hs(string s){
	ll h=1;
	for(char i:s)h=h*997ll+i-95;
	return h;
}
int add(int x,string s){
	for(char i:s){
		if(!f[x][i-97])f[x][i-97]=++k;
		x=f[x][i-97];
	}
	return x;
}
int find(int x,string s){
	for(char i:s)
		if(f[x][i-97])x=f[x][i-97];
	return x;
}
void dfs(int x){
	dfn[x]=++k;
	for(int i=0;i<26;i++)
		if(f[x][i])dfs(f[x][i]);
	dfm[x]=k;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2,t0,t1,t2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l])t1+=s1[l++];
		while(r>l&&s1[r]==s2[r])t2+=s1[r--];
		for(int i=l;i<=r;i++)t0+=s1[i],t0+=s2[i];
		reverse(t1.begin(),t1.end());
		reverse(t2.begin(),t2.end());
		ll h=hs(t0);
		int &z=mp[h];
		if(!z)rt[z=++d]=++k,rt[++d]=++k;
		c[i]={add(rt[z],t1),add(rt[z+1],t2)};
	}
	for(int i=1;i<=d;i++)dfs(rt[i]);
	for(int i=1;i<=n;i++){
		mf[++cnt]={dfn[c[i].fi],dfn[c[i].se],1,0};
		mf[++cnt]={dfn[c[i].fi],dfm[c[i].se]+1,-1,0};
		mf[++cnt]={dfm[c[i].fi]+1,dfn[c[i].se],-1,0};
		mf[++cnt]={dfm[c[i].fi]+1,dfm[c[i].se]+1,1,0};
	}
	for(int i=1;i<=m;i++){
		string s1,s2,t0,t1,t2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())continue;
		int l=0,r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l])t1+=s1[l++];
		while(r>l&&s1[r]==s2[r])t2+=s1[r--];
		for(int i=l;i<=r;i++)t0+=s1[i],t0+=s2[i];
		reverse(t1.begin(),t1.end());
		reverse(t2.begin(),t2.end());
		ll h=hs(t0);
		if(!mp.count(h))continue;
		int z=mp[h];
		pii p={find(rt[z],t1),find(rt[z+1],t2)};
		mf[++cnt]={dfn[p.fi],dfn[p.se],i,1};
	}
	sort(mf+1,mf+cnt+1,[](node x,node y){
		return x.x!=y.x?x.x<y.x:x.t<y.t;
	});
	for(int i=1;i<=cnt;i++)
		if(mf[i].t)ans[mf[i].z]=qry(mf[i].y);
		else mdf(mf[i].y,mf[i].z);
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
