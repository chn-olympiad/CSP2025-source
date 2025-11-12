#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+5,M=1.05e7;
typedef pair<int,int> pii;
int n,T,tr[M][27],tg[N],in[M],A[N],tot,idx,sm[M],fl,sz[M],sn[M];
pii S[N];
vector<array<int,3>>Q,U;
char s[M],t[M];
void upd(int x,int y)
{
	for(;x<M;x+=x&-x)
		sm[x]+=y;
}
int ask(int x)
{
	int s=0;
	for(;x;x-=x&-x)
		s+=sm[x];
	return s;
}
void dfs(int u)
{
	in[u]=++idx,sz[u]=1;
	for(int s=sn[u];s;s&=s-1)
	{
		int i=__builtin_ctz(s);
		dfs(tr[u][i]),sz[u]+=sz[tr[u][i]];
	}
}
int jump(int u,int k)
{
	if(!tr[u][k])
		tr[u][k]=++tot,sn[u]|=1<<k;
	return tr[u][k];
}
void jmp(int&u,int k)
{
	if(!tr[u][k])
		fl=1;
	else
		u=tr[u][k];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s+1,t+1);
		int l=0,r=0;
		for(int i=1;s[i];i++)
			if(s[i]!=t[i])
				l=l? l:i,r=i;
		if(!l)
			continue;
		int u=0;
		for(int i=l;i<=r;i++)
			u=jump(u,s[i]-'a');
		u=jump(u,26);
		for(int i=l;i<=r;i++)
			u=jump(u,t[i]-'a');
		u=jump(u,26);
		int p=u;
		for(int i=l-1;i;i--)
			p=jump(p,s[i]-'a');
		S[i].fi=p;
		p=u;
		for(int i=r+1;s[i];i++)
			p=jump(p,s[i]-'a');
		S[i].se=p;
	}
	dfs(0);
	for(int i=1;i<=n;i++)
	{
		int x=S[i].fi,y=S[i].se;
		if(!x)
			continue;
		U.push_back({in[y],in[x],1});
		U.push_back({in[y],in[x]+sz[x],-1});
		U.push_back({in[y]+sz[y],in[x],-1});
		U.push_back({in[y]+sz[y],in[x]+sz[x],1});
	}
	for(int i=1;i<=T;i++)
	{
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		if(n!=m)
			continue;
		int l=0,r=fl=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i])
				l=l? l:i,r=i;
		int u=0;
		for(int i=l;i<=r;i++)
			jmp(u,s[i]-'a');
		jmp(u,26);
		for(int i=l;i<=r;i++)
			jmp(u,t[i]-'a');
		jmp(u,26);
		if(fl)
			continue;
		int p=u,q=u;
		fl=0;
		for(int i=l-1;i&&!fl;i--)
			jmp(p,s[i]-'a');
		fl=0;
		for(int i=r+1;s[i]&&!fl;i++)
			jmp(q,t[i]-'a');
		Q.push_back({in[q],in[p],i});
	}
	sort(Q.begin(),Q.end());
	sort(U.begin(),U.end());
	int x=0;
	for(auto i:Q)
	{
		while(x!=U.size()&&U[x][0]<=i[0])
			upd(U[x][1],U[x][2]),++x;
		A[i[2]]=ask(i[1]);
	}
	for(int i=1;i<=T;i++)
		printf("%d\n",A[i]);
}
