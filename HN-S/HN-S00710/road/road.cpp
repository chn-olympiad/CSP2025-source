#include<bits/stdc++.h>
#define lint long long
using namespace std;
const int kN=1e4+30,kM=10+10;

struct Node{int u,v,w;};

bool Cmp(Node,Node);
int Merge(int,int);
int Find(int);
void Dfs(int,lint);

Node edge[1100000+100],temp[1100000+100];
int input[kM][kN],fa[kN],n,m,k;lint ans;int tot;

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)scanf("%d",&input[i][j]);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(edge+1,edge+m+1,Cmp);
	lint res=0;
	for(int i=1;i<=m;i++)
		if(Merge(edge[i].u,edge[i].v))
			res+=edge[i].w,temp[++tot]=edge[i];
	for(int i=1;i<=tot;i++)edge[i]=temp[i];
	ans=res,Dfs(1,0ll);
	cout<<ans<<endl;
	return 0;
}

// Node pre[1100000+100];
void Dfs(int dep,lint val)
{
	if(dep==k+1)return;
	Dfs(dep+1,val);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	Node pre[1030];
	for(int i=1;i<=tot;i++)pre[i]=edge[i];int now=tot;
	for(int i=1;i<=n;i++)edge[++tot]={dep+n,i,input[dep][i]};
	sort(edge+1,edge+tot+1,Cmp);
	lint res=val+input[dep][0];int top=0;
	for(int i=1;i<=tot;i++)
		if(Merge(edge[i].u,edge[i].v))
			res+=edge[i].w,temp[++top]=edge[i];
	for(int i=1;i<=top;i++)edge[i]=temp[i];
	tot=top;
	ans=min(ans,res);
	Dfs(dep+1,val+input[dep][0]);
	for(int i=1;i<=now;i++)edge[i]=pre[i];
	tot=now;
}

bool Cmp(Node a,Node b){return a.w<b.w;}

int Merge(int u,int v)
{
	int fax=Find(u),fay=Find(v);
	if(fax!=fay){fa[fax]=fay;return 1;}
	return 0;
}

int Find(int u){return fa[u]==u? u:fa[u]=Find(fa[u]);}