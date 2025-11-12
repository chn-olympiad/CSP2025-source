#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bll __int128
#define vii vector<int>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define sec second
#define Qii queue<int>
#define vll vector<ll>
#define vpi vector<pii>
#define ci const int
using namespace std;
const int N=2e5+5,mod=998244353,base=11451,M=2.5e6+5+N;
const int Mod=1e9+7,Base=19491001;
struct node{int h1,h2,h3,h4,num;}a[N],b[N];
int n,q,m,mm;
vii s1[N],s2[N];
ll ans[N];
string str1,str2;
int SS=0;
inline bool cmp(const node&x,const node&y)
{
	if(x.h1==y.h1)
	{
		if(x.h2==y.h2)
		{
			if(x.h3==y.h3)return x.h4<y.h4;
			return x.h3<y.h3;
		}
		return x.h2<y.h2;
	}
	return x.h1<y.h1;
}
inline bool operator==(const node&x,const node&y){return x.h1==y.h1&&x.h2==y.h2&&y.h3==x.h3&&y.h4==x.h4;}
inline bool operator<(const node&x,const node&y)
{
	if(x.h1==y.h1)
	{
		if(x.h2==y.h2)
		{
			if(x.h3==y.h3)return x.h4<y.h4;
			return x.h3<y.h3;
		}
		return x.h2<y.h2;
	}
	return x.h1<y.h1;
}
struct ACAM
{
	int trans[M][27],fail[M],siz[M],cnt;
	int head[M],nex[M],to[M],tot;
	void add_edge(int x,int y){tot++,nex[tot]=head[x],head[x]=tot,to[tot]=y;}
	void clear()
	{
		for(int i=0;i<=cnt;i++)fail[i]=siz[i]=head[i]=0;tot=0;
		for(int i=0;i<=cnt;i++)for(int j=0;j<=26;j++)trans[i][j]=0;
		cnt=0;
	}
	void ins(const vii&str)
	{
		int n=(int)str.size(),now=0;
		SS+=n;
		for(int i=0;i<n;i++)
		{
			int c=str[i];
			if(!trans[now][c])trans[now][c]=++cnt;
			now=trans[now][c];
		}
		siz[now]++;
	}
	ll ask(const vii&str)
	{
		int n=(int)str.size(),now=0;ll ans=0;
		for(int i=0;i<n;i++)now=trans[now][str[i]],ans+=siz[now];
		return ans;
	}
	void dfs(int x){for(int i=head[x];i;i=nex[i])siz[to[i]]+=siz[x],dfs(to[i]);}
	void build()
	{
		Qii Q;
		for(int i=0;i<=26;i++)if(trans[0][i])Q.push(trans[0][i]);
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();
			for(int i=0;i<=26;i++)
			{
				if(trans[x][i])Q.push(trans[x][i]),fail[trans[x][i]]=trans[fail[x]][i];
				else trans[x][i]=trans[fail[x]][i];
			}
		}
		for(int i=1;i<=cnt;i++)add_edge(fail[i],i);
		dfs(0);
	}
}AC;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>str1>>str2;
		int len=str1.length();
		str1=' '+str1,str2=' '+str2;
		int beg=0,nd=0;
		for(int j=1;j<=len;j++)if(str1[j]!=str2[j]){beg=j;break;}
		for(int j=len;j>=1;j--)if(str1[j]!=str2[j]){nd=j;break;}
		if(!beg)continue;
		int h1=0,h2=0,h3=0,h4=0;
		for(int j=beg;j<=nd;j++)
		{
			h1=(1ll*h1*base+str1[j]-'a'+1)%mod;
			h2=(1ll*h2*base+str2[j]-'a'+1)%mod;
			h3=(1ll*h3*Base+str1[j]-'a'+1)%Mod;
			h4=(1ll*h4*Base+str2[j]-'a'+1)%Mod;
		}
		for(int j=1;j<beg;j++)s1[i].pb(str1[j]-'a');
		s1[i].pb(26);
		for(int j=nd+1;j<=len;j++)s1[i].pb(str1[j]-'a');
		a[++m]=(node){h1,h2,h3,h4,i};
	}
	for(int i=1;i<=q;i++)
	{
		cin>>str1>>str2;
		int len=str1.length();
		str1=' '+str1,str2=' '+str2;
		if(str1.length()!=str2.length())continue;
		int beg=0,nd=0;
		for(int j=1;j<=len;j++)if(str1[j]!=str2[j]){beg=j;break;}
		for(int j=len;j>=1;j--)if(str1[j]!=str2[j]){nd=j;break;}
		int h1=0,h2=0,h3=0,h4=0;
		for(int j=beg;j<=nd;j++)
		{
			h1=(1ll*h1*base+str1[j]-'a'+1)%mod;
			h2=(1ll*h2*base+str2[j]-'a'+1)%mod;
			h3=(1ll*h3*Base+str1[j]-'a'+1)%Mod;
			h4=(1ll*h4*Base+str2[j]-'a'+1)%Mod;
		}
		for(int j=1;j<beg;j++)s2[i].pb(str1[j]-'a');
		s2[i].pb(26);
		for(int j=nd+1;j<=len;j++)s2[i].pb(str1[j]-'a');
		b[++mm]=(node){h1,h2,h3,h4,i};
	}
	sort(a+1,a+1+m,cmp),sort(b+1,b+1+mm,cmp);
	int l=1;
	for(int i=1;i<=mm;i++)
	{
		int las=i;
		while(i<mm&&b[i+1]==b[i])i++;
		while(l<=m&&a[l]<b[i])l++;
		if(l<=m&&b[i]==a[l])
		{
			AC.clear(),AC.ins(s1[a[l].num]);
			while(l<m&&a[l+1]==a[l])l++,AC.ins(s1[a[l].num]);
			AC.build();
			for(int j=las;j<=i;j++)ans[b[j].num]=AC.ask(s2[b[j].num]);
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
}
