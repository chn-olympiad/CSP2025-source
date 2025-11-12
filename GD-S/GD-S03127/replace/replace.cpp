#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

#define p1 998244353
#define p2 1000000007
#define bse 31

const int S=200005,MS=5000005,V=26,P=1145143;

int n,q;
char a[MS],b[MS];
int cnt,to[MS][V],fail[MS];
vector<pair<pair<int,int>,int> > tor[MS];
int hed,til,qq[MS];
vector<int> son[MS];
ll ans[S];
vector<pair<pair<int,int>,int> > vec[P];

inline void insac(int m,int h1,int h2)
{
	int u=0;
	for(int i=1;i<=m;i++)
	{
		int id=a[i]-'a';
		if(to[u][id]==0) to[u][id]=++cnt;
		u=to[u][id];
	}
	tor[u].emplace_back(make_pair(h1,h2),-1);
}
inline void buildac()
{
	hed=1,til=0;
	fail[0]=0; 
	for(int i=0;i<V;i++)
	{
		int &v=to[0][i];
		if(v!=0) qq[++til]=v,fail[v]=0;
		else v=0;
	}
	while(hed<=til)
	{
		int u=qq[hed++];
		int fu=fail[u];
		for(int i=0;i<V;i++)
		{
			int &v=to[u][i];
			if(v!=0) qq[++til]=v,fail[v]=to[fu][i];
			else v=to[fu][i];
		}
	}
	for(int i=1;i<=cnt;i++) son[fail[i]].push_back(i);
}

inline void ins(int h1,int h2,int w)
{
	int x=(1ll*h1*bse+h2)%P;
	auto cur=make_pair(h1,h2);
	for(auto &t:vec[x]) if(t.first==cur) return t.second+=w,void();
	vec[x].emplace_back(cur,w);
}
inline int que(int h1,int h2)
{
	int x=(1ll*h1*bse+h2)%P;
	auto cur=make_pair(h1,h2);
	for(auto &t:vec[x]) if(t.first==cur) return t.second;
	return 0;
}

void doit(int u)
{
	for(auto t:tor[u])
	{
		int h1=t.first.first,h2=t.first.second,id=t.second;
		if(id==-1) ins(h1,h2,1);
	}
	for(auto t:tor[u])
	{
		int h1=t.first.first,h2=t.first.second,id=t.second;
		if(id!=-1) ans[id]+=que(h1,h2);
	}
	for(int v:son[u]) doit(v);
	for(auto t:tor[u])
	{
		int h1=t.first.first,h2=t.first.second,id=t.second;
		if(id==-1) ins(h1,h2,-1);
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int m=strlen(a);
		for(int j=m;j>=1;j--) a[j]=a[j-1],b[j]=b[j-1];
		int h1=0,h2=0;
		for(int j=m;j>=1;j--)
			h1=((1ll*h1*bse+a[j]-b[j])%p1+p1)%p1,
			h2=((1ll*h2*bse+a[j]-b[j])%p2+p2)%p2;
		for(int j=1;j<=m/2;j++) swap(a[j],a[m-j+1]);
		insac(m,h1,h2);
	}
	buildac();
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		int m=strlen(a);
		if(strlen(b)!=m) ans[i]=0;
		else
		{
			for(int j=m;j>=1;j--) a[j]=a[j-1],b[j]=b[j-1];
			int dif=0;
			for(int j=1;j<=m;j++) dif+=(a[j]!=b[j]);
			int h1=0,h2=0;
			int u=0;
			for(int j=m;j>=1;j--)
			{
				h1=((1ll*h1*bse+a[j]-b[j])%p1+p1)%p1;
				h2=((1ll*h2*bse+a[j]-b[j])%p2+p2)%p2;
				dif-=(a[j]!=b[j]);
				u=to[u][a[j]-'a'];
				if(dif==0) tor[u].emplace_back(make_pair(h1,h2),i);
			}
		}
	}
	doit(0);
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
