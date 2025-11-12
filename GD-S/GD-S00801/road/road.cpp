#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 20,maxk = 15;
vector<array<int,3>> tr;
int fa[maxn],siz[maxn];
int find(int x){
	return fa[x] == x?x:fa[x] = find(fa[x]);
}
void merge(int x,int y){
	x = find(x),y = find(y);
	if(x == y)return;
	if(siz[x] < siz[y])swap(x,y);
	fa[y] = x;
	siz[x] += siz[y];
}
bool vis[maxk];
array<int,2> a[maxk][maxn];
int n,m,k;
long long ans,nans;
void dfs(int now,long long nans){
	if(now > k){
		vector<array<int,3>> v(tr),nv;
		for(int i = 1;i <= k;i++)
			if(vis[i]){
				size_t j = 0;
				int k = 1;
				while(j < v.size() || k <= n){
					if(j < v.size() && (k > n || v[j][0] < a[i][k][0]))nv.push_back(v[j++]);
					else nv.push_back({a[i][k][0],i + n,a[i][k][1]}),++k;
				}
				v = nv;
				nv.clear();
			}
		iota(fa+1,fa+n+k+1,1);
		fill(siz+1,siz+n+k+1,1);
		for(auto i:v)
			if(find(i[1]) != find(i[2])){
				merge(i[1],i[2]);
				nans += i[0];
				if(nans >= ans)return;
			}
		ans = min(ans,nans);
		return;
	}
	vis[now] = false;	
	dfs(now + 1,nans);
	vis[now] = true;
	dfs(now + 1,nans + a[now][0][0]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	vector<array<int,3>> e;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back({w,u,v});
	}
	sort(e.begin(),e.end());
	iota(fa+1,fa+n+1,1);
	fill(siz+1,siz+n+1,1);
	for(auto i:e)
		if(find(i[1]) != find(i[2])){
			tr.push_back(i);
			merge(i[1],i[2]);
		}	
	for(int i = 1;i <= k;i++){
		scanf("%d",&a[i][0][0]);
		for(int j = 1;j <= n;j++)
			scanf("%d",&a[i][j][0]),a[i][j][1] = j;
		sort(a[i]+1,a[i]+n+1);
	}
	ans = LLONG_MAX;
	dfs(1,0);
	cout << ans << '\n';
}
