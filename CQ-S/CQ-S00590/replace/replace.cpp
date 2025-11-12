#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,q,totq,rt[2],ch[N][26],dep[N],a[N],b[N],tot=2,fail[N],h[N],cnt,cnt1[2],dfn[N],sz[N],ans[N],tree[N];
struct nn{
	int to,next;
}e[N];
struct Query{
	int x,y,z,op;
}Q[3*N];
bool cmp(Query s,Query t)
{
	if(s.x==t.x)return s.op>t.op;
	return s.x<t.x;
}
string s[2];
void change(int x,int y){for(;x<=cnt1[1];x+=x&-x)tree[x]+=y;}
int solve(int x){int res=0;for(;x;x-=x&-x)res+=tree[x];return res;}
void add(int x,int y){e[++cnt]=(nn){y,h[x]};h[x]=cnt;}
int Insert(int op)
{
	int pos=rt[op];
	for(int i=0;i<s[op].length();i++)
	{
		int x=s[op][i]-'a';
		if(!ch[pos][x])tot++,ch[pos][x]=tot,dep[tot]=dep[pos]+1;
		pos=ch[pos][x];
	}
	return pos;
}
void bfs(int op)
{
	queue<int>q;
	q.emplace(rt[op]);
	for(int i=0;i<26;i++)ch[0][i]=rt[op];
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(!ch[x][i])ch[x][i]=ch[fail[x]][i];
			else{
				int y=ch[x][i];
				fail[y]=ch[fail[x]][i],q.emplace(y);
			}
		}
	}
}
void dfs(int x,int op)
{
	dfn[x]=++cnt1[op],sz[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		dfs(y,op),sz[x]+=sz[y];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q,rt[0]=1,rt[1]=2;
	for(int i=1;i<=n;i++)
	{
		cin>>s[0]>>s[1];
		a[i]=Insert(0),b[i]=Insert(1);
	}
	bfs(0),bfs(1);
	for(int i=3;i<=tot;i++)add(fail[i],i);
	dfs(1,0),dfs(2,1);
	for(int i=1;i<=n;i++)
	{
		Q[++totq]=(Query){dfn[a[i]],dfn[b[i]],dfn[b[i]]+sz[b[i]]-1,1};
		Q[++totq]=(Query){dfn[a[i]]+sz[a[i]]-1,dfn[b[i]],dfn[b[i]]+sz[b[i]]-1,-1};
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.length(),p1=1,p2=2,p3=1,p4=2;
		bool flag=0;
		int cnt=0,lst=0;
		for(int j=0;j<len;j++)if(s1[j]!=s2[j])lst=j;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])flag=1;
			if(flag)cnt++,p3=ch[p3][s1[j]-'a'],p4=ch[p4][s2[j]-'a'];
			p1=ch[p1][s1[j]-'a'],p2=ch[p2][s2[j]-'a'];
			if(j>=lst&&dep[p1]>=cnt)
			{
				Q[++totq]=(Query){dfn[p1],dfn[p2],i,0};
				int t3=p3,t4=p4;
				if(dep[t3]==cnt)t3=fail[t3];
				if(dep[t4]==cnt)t4=fail[t4];
				Q[++totq]=(Query){dfn[t3],dfn[t4],-i,0};
			}
		}
	}
	sort(Q+1,Q+totq+1,cmp);
	for(int i=1;i<=totq;i++)
	{
		if(Q[i].op)change(Q[i].y,Q[i].op),change(Q[i].z+1,-Q[i].op);
		else{
			if(Q[i].z>0)ans[Q[i].z]+=solve(Q[i].y);
			else ans[-Q[i].z]-=solve(Q[i].y);
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}

