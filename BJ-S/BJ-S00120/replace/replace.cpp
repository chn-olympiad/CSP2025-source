#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef long long LL;
const int NR=2e5+5;
const int MR=5e6+5;
char s1[MR],s2[MR];
int tr1[MR][26];
int dep1[MR];
int tr2[MR][26];
int fail1[MR],fail2[MR];
int num1,num2;
int u[NR],v[NR];
struct Edge
{
	int v,nxt;
}g1[MR],g2[MR];
int fte1[MR],fte2[MR];
int gsz1,gsz2;
void ad1(int u,int v)
{
	g1[++gsz1]=(Edge){v,fte1[u]};
	fte1[u]=gsz1;
}
int dfn1[MR],sz1[MR],id1;
int fa1[23][MR];
void dfs1(int x)
{
	dfn1[x]=++id1;
	sz1[x]=1;
	for(int i=fte1[x];i;i=g1[i].nxt)
	{
		int y=g1[i].v;
		dfs1(y);
		fa1[0][y]=x;
		sz1[x]+=sz1[y];
	}
}
void ad2(int u,int v)
{
	g2[++gsz2]=(Edge){v,fte2[u]};
	fte2[u]=gsz2;
}
int dfn2[MR],sz2[MR],id2;
void dfs2(int x)
{
	dfn2[x]=++id2;
	sz2[x]=1;
	for(int i=fte2[x];i;i=g2[i].nxt)
	{
		int y=g2[i].v;
		dfs2(y);
		sz2[x]+=sz2[y];
	}
}
char t1[MR],t2[MR];
bool fff[NR];
struct Query
{
	int y,id,k;
};
vector<Query> qu[MR];
struct Modify
{
	int l,r,k;
};
vector<Modify> mod[MR];
LL ans[MR];
int n,dta[MR];
int lowbit(int x) {return x&(-x);}
void modify(int x,int k) {for(;x<=n;x+=lowbit(x)) dta[x]+=k;}
int query(int x) {int sum=0;for(;x;x-=lowbit(x)) sum+=dta[x];return sum;}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s%s",s1+1,s2+1);
		int l1=strlen(s1+1),l2=strlen(s2+1);
		int nw;
		nw=0;
		for(int j=1;j<=l1;++j)
		{
			if(!tr1[nw][s1[j]-'a']) tr1[nw][s1[j]-'a']=++num1,dep1[num1]=dep1[nw]+1;//,printf("%d %c %d\n",nw,s1[j],num1);
			nw=tr1[nw][s1[j]-'a'];
		}
		u[i]=nw;
		nw=0;
		for(int j=1;j<=l2;++j)
		{
			if(!tr2[nw][s2[j]-'a']) tr2[nw][s2[j]-'a']=++num2;
			nw=tr2[nw][s2[j]-'a'];
		}
		v[i]=nw;
	}
	{
		queue<int> q;
		for(int i=0;i<26;++i) if(tr1[0][i]) q.push(tr1[0][i]);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			//printf("%d %d\n",x,fail1[x]);
			for(int i=0;i<26;++i) 
			{
				if(tr1[x][i]) fail1[tr1[x][i]]=tr1[fail1[x]][i],q.push(tr1[x][i]);
				else tr1[x][i]=tr1[fail1[x]][i];
			}
		}
		for(int i=1;i<=num1;++i) ad1(fail1[i],i);
		dfs1(0);
		for(int i=1;i<23;++i) for(int j=0;j<=num1;++j) fa1[i][j]=fa1[i-1][fa1[i-1][j]];
	}
	{
		queue<int> q;
		for(int i=0;i<26;++i) if(tr2[0][i]) q.push(tr2[0][i]);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			//printf("%d %d\n",x,fail2[x]);
			for(int i=0;i<26;++i) 
			{
				if(tr2[x][i]) fail2[tr2[x][i]]=tr2[fail2[x]][i],q.push(tr2[x][i]);
				else tr2[x][i]=tr2[fail2[x]][i];
			}
		}
		for(int i=1;i<=num2;++i) ad2(fail2[i],i);
		dfs2(0);
	}
	for(int i=1;i<=n;++i)
	{
		mod[dfn1[u[i]]].push_back((Modify){dfn2[v[i]],dfn2[v[i]]+sz2[v[i]]-1,1});
		mod[dfn1[u[i]]+sz1[u[i]]].push_back((Modify){dfn2[v[i]],dfn2[v[i]]+sz2[v[i]]-1,-1});
	}
	::n=id2;
	for(int q=1;q<=Q;++q)
	{
		scanf("%s%s",t1+1,t2+1);
		int l1=strlen(t1+1),l2=strlen(t2+1);
		if(l1!=l2) {fff[q]=1;continue;}
		int st=1,ed=l1;
		while(t1[st]==t2[st]) ++st;
		while(t1[ed]==t2[ed]) --ed;
		int nw1=0,nw2=0;
		for(int i=1;i<=l1;++i)
		{
			nw1=tr1[nw1][t1[i]-'a'];
			nw2=tr2[nw2][t2[i]-'a'];
			if(i>=ed) 
			{
				//printf("%d %d\n",dfn1[nw1],dfn2[nw2]);
				qu[dfn1[nw1]].push_back((Query){dfn2[nw2],q,1});
				int x=nw1;
				if(dep1[nw1]>=i-st+1)
				{
					for(int j=22;j>=0;--j)
					{
						if(dep1[fa1[j][x]]>=i-st+1) x=fa1[j][x];
					}
					x=fa1[0][x];
				}
				qu[dfn1[x]].push_back((Query){dfn2[nw2],q,-1});
			}
		}
	}
	//puts("aaa");
	for(int i=0;i<=id1;++i)
	{
		for(int j=0;j<mod[i].size();++j)
		{
			int k=mod[i][j].k;
			modify(mod[i][j].l,k);
			modify(mod[i][j].r+1,-k);
		}
		for(int j=0;j<qu[i].size();++j)
		{
			ans[qu[i][j].id]+=qu[i][j].k*query(qu[i][j].y);
		}
	}
	for(int i=1;i<=Q;++i) printf("%lld\n",ans[i]);
	return 0;
}