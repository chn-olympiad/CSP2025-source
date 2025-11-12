#include <bits/stdc++.h>
#define MAXN 2000101
#define int long long
#define MAXP 20011
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k,head[MAXN],c[11],a[11][MAXP],ans,fa[MAXN],cnt,extra;
struct node{
	int u,v,w;
}edge[MAXN];
int find(int x) {
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a, node b) {
	return a.w<b.w;
}
void solve1() {
	sort(edge+1,edge+1+cnt,cmp);
	ans=0;
	int tot=0;
	for (int i=1;i<=cnt;i++) {
		int u=edge[i].u,v=edge[i].v;
		int fu=find(u),fv=find(v);
		if (fu==fv) continue;
		fa[fu]=fv;
		ans+=edge[i].w;
		tot++;
		if (tot==n-1) break;
	}
	cout << ans;
}
bool f[11];
int kruskal() {
	sort(edge+1,edge+1+cnt,cmp);
	int tot=0,res=0;
	for (int i=1;i<=cnt;i++) {
		int u=edge[i].u,v=edge[i].v;
		int fu=find(u),fv=find(v);
		if (fu==fv) continue;
		fa[fu]=fv;
		res+=edge[i].w;
		tot++;
		if (tot==extra-1) break;
	}
	return res;
}
void solve2() {
	int now;
	ans=LONG_LONG_MAX;
	for (int op=0;op<=(1<<k)-1;op++) {//each operation 
		cnt=2*m;
		now=0;
		for (int j=1;j<=k;j++) {
			if ((op>>(j-1))&1) f[j]=true;
			else f[j]=false;
		}
		extra=n;
		for (int i=1;i<=k;i++){
			if (!f[i]) continue;
			now+=c[i];
			++extra;
			for (int j=1;j<=n;j++) {
				edge[++cnt].u=extra,edge[cnt].v=j,edge[cnt].w=a[i][j];
				edge[++cnt].v=extra,edge[cnt].u=j,edge[cnt].w=a[i][j];
			}
		}
		for (int i=1;i<=extra;i++) fa[i]=i;
		now+=kruskal();
		ans=min(ans,now);
	}
	cout << ans << endl;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		edge[++cnt].u=u,edge[cnt].v=v,edge[cnt].w=w;
		edge[++cnt].u=v,edge[cnt].v=u,edge[cnt].w=w;
	}
	for (int i=1;i<=k;i++) {
		c[i]=read();
		for (int j=1;j<=n;j++) a[i][j]=read();
	}
	if (k==0) solve1();
	else solve2();
	return 0;
}
//the last time taking part in CSP-S has been ruined
//that's rediculous
//why have I reviewed almost all the algorithms and data structures I have learned but only ignore PRIM!
//four years, I have studied OI for four years(though I have AFOed for one year)
//in my memory, I have never seen ONE problem must need PRIM in contests
//regret...upset...angry...
//the sense of desperation......that feels like I can do the math problem but I forget how to use pen!
//maybe it's just my fate......
//maybe I, who has been AFOed for a long time, should not partake in this year's OI contests
//Hope I can cheer up soon
//Hope whk RP++
//Hope the last NOIp RP++
