#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;
mt19937 rd(time(0));
const int N=2e5+5,M=25e5+5,mod=998244853;
int n,q,tr[M][26],tr2[M][26],dfn[M],dfn2[M],nm,ans[N],to[N],to2[N],h[N],h2[N],cnt,cnt2,num,num2,al,tr3[M];
ll ha[26],ha2[26];
pair<ll,ll> hs[N],hs2[N];
map<pair<ll,ll>,int>mp;
string s,s2,la[N],ra[N],l[N],r[N];
vector<int>v[N],v2[N];
struct node{int next,to;}a[M],b[M];
void ad(int x,int y){a[++cnt]={h[x],y},h[x]=cnt;}
void ad2(int x,int y){b[++cnt2]={h2[x],y},h2[x]=cnt2;}
void pls(pair<ll,ll> &x,char y){x.fir=(x.fir*31+ha[y-'a'])%mod,x.sec=(x.sec*37+ha2[y-'a'])%mod;}
void ad3(int x,int y){for(int i=x;i<=al;i+=(i&-i)) tr3[i]+=y;}
int ask(int x){int nw=0;for(int i=x;i;i-=(i&-i)) nw+=tr3[i];return nw;}
void add(string x,int y)
{
	int w=x.length();int nw=0;
	for(int i=0;i<w;i++){int z=x[i]-'a';if(!tr[nw][z]) tr[nw][z]=++num;nw=tr[nw][z];}
	ad(nw,y);
}
void add2(string x,int y)
{
	int w=x.length();int nw=0;
	for(int i=0;i<w;i++){int z=x[i]-'a';if(!tr2[nw][z]) tr2[nw][z]=++num2;nw=tr2[nw][z];}
	to[y]=nw;
}
void add3(string x,int y)
{
	int w=x.length();int nw=0;
	for(int i=0;i<w;i++){int z=x[i]-'a';if(!tr[nw][z]) break;nw=tr[nw][z];}
	ad2(nw,y);
}
void add4(string x,int y)
{
	int w=x.length();int nw=0;
	for(int i=0;i<w;i++){int z=x[i]-'a';if(!tr2[nw][z]) break;nw=tr2[nw][z];}
	to2[y]=nw;
}
void dfs(int x)
{
	dfn[x]=++al;
	for(int i=0;i<26;i++) if(tr2[x][i]) dfs(tr2[x][i]);
	dfn2[x]=al;
}
void dfs2(int x)
{
	for(int i=h[x];i;i=a[i].next){int k=to[a[i].to];ad3(dfn[k],1),ad3(dfn2[k]+1,-1);}
	for(int i=h2[x];i;i=b[i].next){int k=b[i].to;ans[k]=ask(dfn[to2[k]]);}
	for(int i=0;i<26;i++) if(tr[x][i]) dfs2(tr[x][i]);
	for(int i=h[x];i;i=a[i].next){int k=to[a[i].to];ad3(dfn[k],-1),ad3(dfn2[k]+1,1);}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;for(int i=0;i<26;i++) ha[i]=rd()%mod,ha2[i]=rd()%mod;
	for(int x,i=1;i<=n;i++)
	{
		cin>>s>>s2,x=s.length();int ls=-1,rs=-1;
		for(int j=0;j<x;j++) if(s[j]!=s2[j]) {if(ls<0) ls=j;rs=j;}
		if(ls<0) continue;
		for(int j=ls-1;j>=0;j--) la[i]+=s[j];
		for(int j=rs+1;j<x;j++) ra[i]+=s[j];
		for(int j=ls;j<=rs;j++) pls(hs[i],s[j]);
		for(int j=ls;j<=rs;j++) pls(hs[i],s2[j]);
		if(!mp[hs[i]]) mp[hs[i]]=++nm;v2[mp[hs[i]]].push_back(i);
	}
	for(int x,i=1;i<=q;i++)
	{
		cin>>s>>s2,x=s.length();if(x!=s2.length()) continue;int ls=-1,rs=-1;
		for(int j=0;j<x;j++) if(s[j]!=s2[j]) {if(ls<0) ls=j;rs=j;}
		for(int j=ls-1;j>=0;j--) l[i]+=s[j];
		for(int j=rs+1;j<x;j++) r[i]+=s[j];
		for(int j=ls;j<=rs;j++) pls(hs2[i],s[j]);
		for(int j=ls;j<=rs;j++) pls(hs2[i],s2[j]);
		if(mp[hs2[i]]) v[mp[hs2[i]]].push_back(i);
	}
	for(int i=1;i<=nm;i++)
	{
		if(v[i].empty()||v2[i].empty()) continue;
		for(auto j:v2[i]) add(la[j],j),add2(ra[j],j);dfs(0);
		for(auto j:v[i]) add3(l[j],j),add4(r[j],j);dfs2(0);
		for(int j=0;j<=num;j++){h[j]=h2[j]=0;for(int k=0;k<26;k++) tr[j][k]=0;}
		for(int j=0;j<=num2;j++) for(int k=0;k<26;k++) tr2[j][k]=0;
		num=num2=al=cnt=cnt2=0;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
