#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,k;
struct Edge{
	int to1,to2,w;
	bool operator<(const Edge& other) const
	{return this->w>other.w;}
}; vector<Edge> v[(int)(1e4+5)];
int c[15];int a[15][(int)(1e4+5)];
priority_queue<Edge> qIN;
bool vis[(int)(1e4+5)];int cntE=0;
int ans=0;

void prim(){
	vis[1]=true;
	for (int i=0;i<v[1].size();++i)
		qIN.push(v[1][i]);
	while (cntE!=n-1){
		Edge now=qIN.top();
		qIN.pop();
		if (vis[now.to1]&&vis[now.to2])
			continue;
		vis[now.to2]=true;cntE++;ans+=now.w;
		for (int i=0;i<v[now.to2].size();++i){
			if (vis[v[now.to2][i].to2]) continue;
			qIN.push(v[now.to2][i]);
		}
	} return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int ui,vi,wi;
	for (int i=1;i<=m;++i){
		cin >> ui >> vi >> wi;
		v[ui].push_back({ui,vi,wi});
		v[vi].push_back({vi,ui,wi});
	} for (int i=1;i<=k;++i){
		cin >> c[i];
		for (int j=1;j<=n;++j)
			cin >> a[i][j];
	} if (k==0){
		prim();
		cout << ans;
	} else{
		//Because I dont know how to do this program,I decide to check my good luck:)
		prim();
		cout << ans;
	} return 0;
}

//VERY Actually Im a JVRUO:<
//By Luogu@YzxLeaf's CSP-S2 Alone.At 18p.m.On 2025-11-01.
//All Rights Reserved.
