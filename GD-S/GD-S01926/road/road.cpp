#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
struct node{
	int v, w, f, id;
};
vector<node> vc[10005];
int n, m, k, a[10005], t[10005], dis[10005], vis[10005], co[10005];
map<pair<int, int>,int> mp;
void dij(){
	dis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(vis[now]!=0)continue;
		vis[now]=1;
		for(int i=0;i<vc[now].size();i++){
			int to=vc[now][i].v, ww=vc[now][i].w, fl=vc[now][i].f, d=vc[now][i].id;
			if(dis[to]>ww){
				dis[to]=ww;
				if(fl==1)co[to]=d;
				else co[to]=0;
				if(vis[to]==0)q.push(to);
			}
		}
	}
}
int v[10005];
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dis, inf, sizeof(dis));
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int x, y, z;
		cin >> x >>y >> z;
		vc[x].push_back({y, z, 0, 0});
		vc[y].push_back({x, z, 0, 0});
	}
	for(int i=1;i<=k;i++){
		cin >> a[i];
		for(int j=1;j<=n;j++){
			cin >> t[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				vc[k].push_back({j, t[k]+t[j], 1, i});
				vc[j].push_back({k, t[k]+t[j], 1, i});
			}
		}
	}
	dij();
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dis[i];
		if(co[i]!=0&&v[co[i]]==0){
			v[co[i]]=1;
			ans+=a[co[i]];
		}
	}
	cout << ans << endl;
	return 0;
}
