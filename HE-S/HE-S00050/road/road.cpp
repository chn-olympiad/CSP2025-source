#include<bits/stdc++.h>
#define int long long

using namespace std;

const int SIZN = 1e4 + 10;
const int SIZM = 1e6 + 10;

struct node{
	int u,v,w;
};

int n,m,k;
int ans = 0;
int c[SIZN];
int fa[SIZN];
int mp[50][SIZN];
node road[SIZM + 50 * SIZM];
int cnt;
bool cmp(node a,node b){
	return a.w < b.w;
}
int root(int x){
	if(fa[x] == x)return x;
	else return fa[x] = root(fa[x]);
}
void merge(int x,int y){
	x = root(x);
	y = root(y);
}
int hsk(){
	int tot = 0;
	int pos = 1;
	while(tot != n - 1){
		int x = road[pos].u;
		int y = road[pos].v;
		int w = road[pos].w;
		pos++;
		
		if(root(x) != root(y)){
			merge(x,y);
			tot++;
			ans += w;
		}
	}
	cout << ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		cin >> road[i].u >> road[i].v >> road[i].w;
	}
	for(int i = 1 ; i <= n ; i++)fa[i] = i;
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i];
		for(int j = 1 ; j <= n ; j++){
			cin >> mp[i][j];
			for(int k = 1 ; k < j ; k++){
				road[++m] = node{k,j,mp[i][k] + mp[k][j]};
			}
		}
	}
	sort(road+1,road+m+1,cmp);
	hsk();
	return 0;
}
