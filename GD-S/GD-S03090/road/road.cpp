#include <bits/stdc++.h>
using namespace std;
struct node{
	int u=0,v=0,w=0;
};
vector<node> e;
int c[30];
int d[30];
int a[30][10060];
int fa[10060];
int ans=1e9,n,m,k;
int find(int a1){
	if (a1 == fa[a1])return a1;
	fa[a1] = find(fa[a1]);
	return fa[a1];
}
void Union(int a1,int b1){
	fa[a1] = fa[b1];
	find(a1);
	find(b1);
}
bool cmp(node a1,node b1){return a1.w < b1.w;}
int vis[30];
void check(){
	for (int i=1;i<=n+k;i++)fa[i] = i;
	vector<node> f;
	int test = e.size();
	for (int i=0;i<=test;i++)f.push_back(e[i]);
	for (int i=1;i<=k;i++){
		int max1 = c[i];
		if (vis[i] == 0)continue;//ûѡ 
		for (int j=1;j<=m;j++){
			if (e[j].w > a[i][e[j].u]+a[i][e[j].v]){
				f[j].w = a[i][e[j].u]+a[i][e[j].v];
			}
		}
		if (max1 < 0)d[i] = 1;
	}
	sort(f.begin()+1,f.end()+1,cmp);
	int sum1 = 0,l=1;
	for (int i=1;i<=k;i++)sum1 += c[i]*vis[i];
	for (int i=1;i<n;i++){
		if (find(f[l].u) == find(f[l].v)){
			l++;
			continue;
		}
		Union(f[l].u,f[l].v);
		sum1 += f[l].w;
		l++;
	}
	ans = min(ans,sum1);
}
void dfs(int index){
	if (index > n){
		check();
		return;
	}
	if (d[index] == 1){
		vis[index] = 1;
		dfs(index+1);
		vis[index] = 0;
	}
	dfs(index+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	node now;
	now.w = -100;
	e.push_back(now);
	for (int i=1;i<=n+k;i++)fa[i] = i;
	for (int i=1;i<=m;i++){
		node now;
		cin >> now.u >> now.v >> now.w;
		e.push_back(now);
	}
	for (int i=1;i<=k;i++){
		cin >> c[i];
		for (int j=1;j<=n;j++)cin >> a[i][j];
	}
	sort(e.begin()+1,e.end()+1,cmp);
	int sum1 = 0,l=1;
	for (int i=1;i<n;i++){
		if (find(e[l].u) == find(e[l].v)){
			l++;
			continue;
		}
		Union(e[l].u,e[l].v);
		sum1 += e[l].w;
		l++;
	}
	for (int i=1;i<=k;i++){
		int max1 = c[i];
		for (int j=1;j<=m;j++){
			if (e[j].w > a[i][e[j].u]+a[i][e[j].v]){
				max1 += a[i][e[j].u]+a[i][e[j].v]-e[j].w;
			}
		}
		if (max1 < 0)d[i] = 1;
	}
	dfs(1);
	cout << sum1;
	return 0;
}
