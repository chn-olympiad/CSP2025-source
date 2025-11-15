#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,ans,tmp,cnt;
vector<int> c,root,cur,pt;
vector<vector<pair<int,int>>> a;
vector<pair<int,pair<int,int>>> edge;
vector<vector<pair<int,pair<int,int>>>> road;

vector<pair<int,int>> seg;

void update(int id,int l,int r,int p,int x){
	if(l==r){
		seg[id]={p,x};
		return;
	}
	int m=(l+r)/2;
	if(p<=m){
		update(id*2,l,m,p,x);
	}else{
		update(id*2+1,m+1,r,p,x);
	}
	if(seg[id*2].second<seg[id*2+1].second){
		seg[id]=seg[id*2];
	}else{
		seg[id]=seg[id*2+1];
	}
}

int find_root(int u){
	if(cur[u]==u){
		return u;
	}
	return cur[u]=find_root(cur[u]);
}

bool merge(int u,int v){
	u=find_root(u);
	v=find_root(v);
	if(u==v){
		return false;
	}
	cur[u]=v;
	return true;
}

void solve(){
	cin >> n >> m >> k;
	c.resize(k);a.resize(k);edge.resize(m);root.resize(n+1);road.resize(k+1);pt.resize(k+1);seg.resize(4*k+9);
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	for(int i=0;i<m;i++){
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
	}
	sort(edge.begin(),edge.end());
	cur=root;
	road[k].reserve(n-1);
	for(int i=0;i<m;i++){
		if(merge(edge[i].second.first,edge[i].second.second)){
			ans+=edge[i].first;
			road[k].push_back(edge[i]);

		}
	}
	for(int i=0;i<k;i++){
		cin >> c[i];
		a[i].resize(n);
		for(int j=0;j<n;j++){
			cin >> a[i][j].first;
			a[i][j].second=j+1;
		}
		sort(a[i].begin(),a[i].end());
		road[i].resize(n-1);
		for(int j=1;j<n;j++){
			road[i][j-1]={a[i][j].first,{a[i][0].second,a[i][j].second}};
		}
	}
	for(int i=1;i<(1<<k);i++){
		cur=root;tmp=0;cnt=0;
		for(int j=0;j<=k;j++){
			pt[j]=0;
			if((1<<j)&i){
				tmp+=c[j]+a[j][0].first;
				update(1,0,k,j,road[j][0].first);
			}else{
				update(1,0,k,j,1e9+7);
			}
		}
		update(1,0,k,k,road[k][0].first);
		while(cnt<n-1){
			int u=seg[1].first;
			if(merge(road[u][pt[u]].second.first,road[u][pt[u]].second.second)){
				tmp+=road[u][pt[u]].first;
				cnt++;
			}
			if(++pt[u]<n-1){
				update(1,0,k,u,road[u][pt[u]].first);
			}else{
				update(1,0,k,u,1e9+7);
			}
		}
		ans=min(ans,tmp);
	}
	cout << ans << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	// cin >> T;
	while(T--){
		solve();
	}
}