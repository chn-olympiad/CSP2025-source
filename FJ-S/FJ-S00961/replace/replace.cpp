#include <bits/stdc++.h>
#define fi first
#define se second
#define mk(x,y) (make_pair(x,y))
#define ll long long
using namespace std;
const int T=5e6+100;
const int N=2e5+100;
const ll mod1=1e9+7,mod2=1e9+9,K=131;
int ch[T][27],fail[T];
char s[T],t[T];
int n,q;

pair<int,pair<ll,ll>> change(int len)//s,t
{
	int l=0,r=0;
	for(int i=1;i<=len;++i)
	{
		if(s[i]!=t[i])
		{
			r=i;
			if(!l)
			l=i;
		}
	}
	if(!l)
	return mk(-1,mk(-1,-1));
	ll h1=0,h2=0;
	for(int i=l;i<=r;++i)
	{
		h1=(h1*K+s[i])%mod1;
		h1=(h1*K+t[i])%mod1;
		
		h2=(h2*K+s[i])%mod2;
		h2=(h2*K+t[i])%mod2;
	}
	s[l]='a'+26;
	for(int i=r+1;i<=len;++i)
	{
		s[i-(r-l)]=s[i];
	}
	return mk(len-(r-l),mk(h1,h2));
}
int tot=N+1,cnt=0;
int num[T];
void insert(int root,int len)//s
{
	int now=root;
	for(int i=1;i<=len;++i)
	{
		if(!ch[now][s[i]-'a'])
		{
			ch[now][s[i]-'a']=++tot;
		}
		now=ch[now][s[i]-'a'];
	}
	++num[now];
}
map<pair<ll,ll>,int> mp;
queue<int> que;
void build_AC(int root)
{
	fail[root]=root;
	for(int i=0;i<=26;++i)
	{
		if(ch[root][i])
		{
			fail[ch[root][i]]=root;
			que.push(ch[root][i]);
		}
		else
		{
			ch[root][i]=root;
		}
	}
	while(!que.empty())
	{
		int t=que.front();
		que.pop();
		num[t]+=num[fail[t]];
		for(int i=0;i<=26;++i)
		{
			if(ch[t][i])
			{
				fail[ch[t][i]]=ch[fail[t]][i];
				que.push(ch[t][i]);
			}
			else
			{
				ch[t][i]=ch[fail[t]][i];
			}
		}
	}
}
int query(int root,int len)
{
	int res=0;
	int now=root;
	for(int i=1;i<=len;++i)
	{
		now=ch[now][s[i]-'a'];
		res+=num[now];
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>(s+1)>>(t+1);
		pair<int,pair<ll,ll>> tmp=change(strlen(s+1));
		if(tmp.fi==-1)
			continue ;
		int id=mp[tmp.se];
		if(!id)
		{
			id=mp[tmp.se]=++cnt;
		}
		insert(id,tmp.fi);
	}
	for(int i=1;i<=N;++i)
	{
		build_AC(i);
	}
	for(int i=1;i<=q;++i)
	{
		cin>>(s+1)>>(t+1);
		int slen=strlen(s+1);
		int tlen=strlen(t+1);
		if(slen!=tlen)
		{
			cout<<0<<'\n';
			continue ;
		}
		pair<int,pair<ll,ll>> tmp=change(slen);
		cout<<query(mp[tmp.se],tmp.fi)<<'\n';
	}
	//cout<<tot<<'\n';
	return 0;
}
















