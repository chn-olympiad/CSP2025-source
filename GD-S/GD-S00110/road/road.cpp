#include<bits/stdc++.h>
# define Maxn 10025
# define Maxm 1000005
# define ll long long
using namespace std;
int n,m,k,tot,fa[Maxn],st1,st2,sz;
ll c[12],a[12][Maxn],now,ans=1e18;
struct Node{int u,v;ll w;}e[Maxm],d[Maxm];
bool cmp(Node x,Node y) {return x.w<y.w;}
ll Min(ll x,ll y) {return x<y?x:y;}
ll Max(ll x,ll y) {return x<y?x:y;}
int find(int x) {
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
char ch;
int read() {
	int v=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') v=v*10+ch-'0',ch=getchar();
	return v;
}
ll read1() {
	ll v=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') v=1ll*v*10+ch-'0',ch=getchar();
	return v;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	e[i].u=read(),e[i].v=read(),e[i].w=read1();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++) {
		c[i]=read1();
		for(int j=1;j<=n;j++)
		a[i][j]=read1();
	}
	for(int s=0;s<(1<<k);s++) {
		tot=now=sz=0;
		st1=st2=1;
		for(int j=0;j<k;j++) {
			if((s>>j)&1) {
				now+=c[j+1],sz++;
				for(int i=1;i<=n;i++)
				d[++tot]={j+1+n,i,a[j+1][i]};
			}
		}
		sort(d+1,d+tot+1,cmp);
		int cnt=0;
		for(int i=1;i<=n+k;i++)
		fa[i]=i;
		while(1) {
			if(now>=ans) break;
			bool bz=0;
			int u=0,v=0;
			ll w=1e9+1;
			if(st1<=m&&w>=e[st1].w) u=e[st1].u,v=e[st1].v,w=e[st1].w,bz=0;
			if(st2<=tot&&w>d[st2].w) u=d[st2].u,v=d[st2].v,w=d[st2].w,bz=1;
			int f1=find(u),f2=find(v);
			if(!bz) st1++;
			else st2++;
			if(f1!=f2) {
				cnt++;
				now+=w;
				fa[f1]=f2;
			}
			if(cnt==n+sz-1) break;
		}ans=Min(ans,now);
	}printf("%lld\n",ans);
	return 0;
}
