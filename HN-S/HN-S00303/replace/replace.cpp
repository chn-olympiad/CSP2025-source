#include<bits/stdc++.h>
#define maxs 2500006
#define maxn 200005
#define pii std::pair<int,int>
#define fi first
#define sc second
const int mod = (1e4+5e4+1971810)*233+19;
int n,q,mxlen,rt1[maxn],rt2[maxn],cnt,ans[maxn],pos1[maxn],pos2[maxn],tot;
int dfnl[maxs],dfnr[maxs];
std::vector<pii>a[maxs],b[maxs];
char s[maxs],t[maxs],s1[maxs],s2[maxs];
std::map<pii,int>mp;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')f = ch == '-'?-f:f,ch = getchar();
	while(ch>='0'&&ch<='9')x = (x<<3)+(x<<1)+(ch^'0'),ch = getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)x = -x,putchar('-');
	static char sta[30];int top = 0;
	do sta[top++] = x%10,x/=10;while(x);
	while(top)putchar(sta[--top]^'0');
	putchar('\n');
}
namespace bit
{
	int c[maxs];
	inline void insert(int x,int v){while(x<=mxlen)c[x]+=v,x+=-x&x;}
	inline int query(int x){int ret = 0;while(x)ret+=c[x],x^=-x&x;return ret;}
} 
namespace tr
{
	int nxt[maxs][26],dfn;
	inline int insert(int p,char*s,int len)
	{
		for(int i = 1,c;i<=len;++i)
		{
			c = s[i]-'a';
			if(!nxt[p][c])nxt[p][c] = ++cnt;
			p = nxt[p][c];
		}
		return p;
	}
	inline int find(int p,char*s,int len)
	{
		for(int i = 1,c;i<=len;++i)
		{
			c = s[i]-'a';
			if(!nxt[p][c])return p;
			p = nxt[p][c];
		}
		return p;
	}
	inline void dfs(int u)
	{
		dfnl[u] = ++dfn;
		for(int i = 0;i<26;++i)
			if(nxt[u][i])dfs(nxt[u][i]);
		dfnr[u] = dfn;
	}
	inline void dfs1(int u)
	{
		for(pii p:a[u])
		{
			bit::insert(p.fi,1);
			bit::insert(p.sc+1,-1);
		}
		for(pii p:b[u])
			ans[p.sc] = bit::query(p.fi);
		for(int i = 0;i<26;++i)
			if(nxt[u][i])dfs1(nxt[u][i]);
		for(pii p:a[u])
		{
			bit::insert(p.fi,-1);
			bit::insert(p.sc+1,1);
		}
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),q = read();
	for(int i = 1,l,r,len,len1,len2,hsh1,hsh2,now;i<=n;++i)
	{
		scanf("%s%s",s+1,t+1),len = strlen(s+1);
		l = 1,r = len,len1 = len2 = hsh1 = hsh2 = 0;
		while(s[l] == t[l]&&l<=len)++l;
		while(s[r] == t[r]&&r>=1)--r;
		if(l>len&&r<1)continue;
		for(int i = l-1;i;--i)s1[++len1] = s[i];
		for(int i = r+1;i<=len;++i)s2[++len2] = s[i];
		for(int i = l;i<=r;++i)hsh1 = (1ll*hsh1*27+s[i]-'a')%mod;
		for(int i = l;i<=r;++i)hsh2 = (1ll*hsh2*27+t[i]-'a')%mod;
		if(!mp[pii(hsh1,hsh2)])mp[pii(hsh1,hsh2)] = ++tot,rt1[tot] = ++cnt,rt2[tot] = ++cnt;
		now = mp[pii(hsh1,hsh2)];
		s1[len1+1] = s2[len2+1] = 0;
		pos1[i] = tr::insert(rt1[now],s1,len1);
		pos2[i] = tr::insert(rt2[now],s2,len2);
	}
	for(int i = 1;i<=tot;++i)
		tr::dfs(rt2[i]),mxlen = std::max(mxlen,tr::dfn),tr::dfn = 0;
	for(int i = 1;i<=n;++i)
		a[pos1[i]].push_back(pii(dfnl[pos2[i]],dfnr[pos2[i]]));
	for(int i = 1,pos1,pos2,len,len1,len2,l,r,hsh1,hsh2,now;i<=q;++i)
	{
		scanf("%s%s",s+1,t+1),len = strlen(s+1);
		l = 1,r = len,len1 = len2 = hsh1 = hsh2 = 0;
		while(s[l] == t[l]&&l<=len)++l;
		while(s[r] == t[r]&&r>=1)--r;
		for(int i = l-1;i;--i)s1[++len1] = s[i];
		for(int i = r+1;i<=len;++i)s2[++len2] = s[i];
		for(int i = l;i<=r;++i)hsh1 = (1ll*hsh1*27+s[i]-'a')%mod;
		for(int i = l;i<=r;++i)hsh2 = (1ll*hsh2*27+t[i]-'a')%mod;
		if(!mp[pii(hsh1,hsh2)])continue;
		now = mp[pii(hsh1,hsh2)];
		pos1 = tr::find(rt1[now],s1,len1);
		pos2 = tr::find(rt2[now],s2,len2);
		b[pos1].push_back(pii(dfnl[pos2],i));
	}
	for(int i = 1;i<=tot;++i)tr::dfs1(rt1[i]);
	for(int i = 1;i<=q;++i)write(ans[i]);
	return 0;
}
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a


