#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int c[N],ca[15][N],fa[N],vis[N];
int n,m,k,kn,km;

struct node{
	int u,v,w;
};

bool cmp(node a,node b){
	return a.w < b.w;
}

vector<node> B_edge;

void init(){
	for(int i = 0;i <= kn;i ++) fa[i] = i;
}

int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

void merge(int x,int y){
	fa[get(x)] = get(y); 
}

int dfs(int x){
	if(x == k + 1){
		vector<node> edge = B_edge;
		int sumb = 0,ssum = 0;
		for(int i = 1;i <= k;i ++){
			if(vis[i]){
				sumb ++;
				ssum += c[i];
				for(int j = 1;j <= n;j ++){
					edge.push_back({n + i,j,ca[i][j]});
				}
			}
		}
		kn = sumb + n,km = edge.size();
		init();
		int ans = ssum; 
		sort(edge.begin(),edge.end(),cmp);
		int ss = 0;
		for(int i = 0;i < km;i ++){
			int u = edge[i].u,v = edge[i].v,w = edge[i].w;
			if(get(u) != get(v)){
				merge(u,v);
				ans += w;
				ss ++;
			}
		}
		return ans;
	}
	int ans = 1e9;
	vis[x] = 1;
	ans = min(ans,dfs(x + 1));
	vis[x] = 0;
	ans = min(ans,dfs(x + 1));
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		B_edge.push_back({u,v,w});
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> ca[i][j];
		}
	}
	cout << dfs(1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
