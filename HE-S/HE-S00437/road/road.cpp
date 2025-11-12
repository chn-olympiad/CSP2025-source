#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cnt,pa[10040];
bool vis[20];
int find(int x){
	if (pa[x]==x){
	return x;
	}else{
	return pa[x]=find(pa[x]);
	}
}
struct T{
	int u,v,w;
	struct N{
	int u;
	};
	operator < (const T b) const {
	return w>b.w;
	}
};
priority_queue<T> q;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
	int u,v,w;
	cin >> u >> v >> w;
	q.push({u,v,w});
	}
	for (int i=1;i<=n;i++){
	pa[i]=i;
	}
	while (q.size()>0&&cnt!=n-1){
	while (q.size()>0&&find(q.top().u)==find(q.top().v)){
	q.pop();
	}
	if (q.size()>0){
	pa[q.top().u]=find(pa[q.top().v]);
	ans+=q.top().w;
	q.pop();
	cnt++;
	}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
