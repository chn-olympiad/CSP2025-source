#include <bits/stdc++.h>
using namespace std;
struct f {
	int u,v,pos;
	long long w;
} g[1000010];
int n,m,k,cnt;
long long c[14],a[14][10010];
bool con[10010][10010],vis[10010][10010],used[14];
bool cmp(f a,f b) {
	return a.w<b.w;
}
bool check() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i!=j) {
				if(con[i][j]==false) {
					return false;
				}
			}
		}
	}
	return true;
}
void sousuo(int a,int b) {
	con[a][b]=con[b][a]=true;
	vis[a][b]=vis[b][a]=true;
	for(int i=1; i<=cnt; i++) {
		if(i!=a&&i!=b&&vis[i][b]==false&&con[i][a]==true) {
			sousuo(i,b);
		}
	}
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			con[i][j]=false;
		}
	}
	cnt=m;
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
			g[cnt].pos=i;
			g[cnt].u=i+n;
			g[cnt].v=j;
			g[cnt].w=a[i][j]+c[i];
			cnt++;
		}
	}
	sort(g,g+cnt,cmp);
	memset(used,false,sizeof(used));
	long long ans=0;
	for(int i=0; check()==false; i++) {
		if(g[i].u>n) {
			if(used[g[i].pos]==true) {
				ans=ans-c[g[i].pos];
			} else {
				used[g[i].pos]=true;
			}
		}
		memset(vis,false,sizeof(vis));
		sousuo(g[i].u,g[i].v);
		memset(vis,false,sizeof(vis));
		sousuo(g[i].v,g[i].u);
		ans=ans+g[i].w;
	}
	cout<<ans;
	return 0;
}
