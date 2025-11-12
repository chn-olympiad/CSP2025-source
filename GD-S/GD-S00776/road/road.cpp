#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return f?x:-x;
}
int n,m,k,head[11100],cnt,q[1024],l[1024][11100];
bool vis[1024][11100];
struct node {
	int v,w,nxt;
}e[3000006];
void add(int u,int v,int w) {
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
void pri() {
	memset(l,0x3f,sizeof(l));
	set<pair<int,int> >mp;
	mp.insert({0,1}),l[0][1]=0;
	while(!mp.empty()) {
		pair<int,int>an;
		int mx=INF;
		auto kxk=mp.begin();
		for(auto it=mp.begin();it!=mp.end();it ++) {
			pair<int,int>o=(*it);
			if(mx>l[o.first][o.second]) kxk=it,mx=l[o.first][o.second],an=o;
		}
		int t=an.first,u=an.second;
		mp.erase(kxk);
		if(vis[t][u]==1) continue;
		q[t]+=l[t][u],vis[t][u]=1;
		for(int i = head[u];i;i = e[i].nxt) {
			int v=e[i].v,tt=t,w=e[i].w;
			if(v>n) tt=tt|(1<<(v-n-1));
			if(t!=tt) w=0;
			l[tt][v]=min(l[tt][v],w);
			if(vis[tt][v]==0) mp.insert({tt,v});
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i <= m;i ++) {
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	for(int i = 1;i <= k;i ++) {
		int a=read();
		for(int j = 0;j < (1<<k);j ++) if((j&(1<<(i-1)))!=0) q[j]+=a;
		for(int j = 1;j <= n;j ++) {
			int w=read();
			add(i+n,j,w),add(j,i+n,w);
		}
	}
	pri();
	int ans=INF;
	for(int j = 0;j < (1<<k);j ++) ans=min(ans,q[j]);
	cout << ans;
	return 0;
}
