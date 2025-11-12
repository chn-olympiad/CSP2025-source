#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> edge[10100];
int w[10100][10100] = {0};
int a[10100][10100] = {0};
int c[10100] = {0};
bool visited[20000] = {false};
bool citied[20] = {false};
int coun;

inline int fastread() {
	int rst = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(ch!=EOF && isdigit(ch)) {
		rst = rst * 10 + ch - '0';
		ch = getchar();
	}
	return rst;
}

int dfs(int cnt, int x) {
	if(cnt==n) return 0;
	int rst = 0x7fffffff;
	if(n<x) {
		for(int i=1;i<=n;i++) {
			if(!visited[i]) {
				visited[i] = true;
				rst = min(rst, dfs(cnt+1,i)+a[x-n][i]);
				visited[i] = false;
			}
		}
		return rst;
	}
	for(int i=0,len=edge[x].size();i<len;i++) {
		int dst = edge[x][i];
		if(!visited[dst]) {
			visited[dst] = true;
			rst = min(rst, dfs(cnt+1,dst)+w[x][dst]);
			visited[dst] = false;
		}
	}
	for(int i=n+1;i<=n+k;i++) {
		if(!visited[i]) {
			visited[i] = true;
			rst = min(rst, dfs(cnt,i)+a[i-n][x]);
			visited[i] = false;
		}
	}
	return rst;
}

inline int search(int x) {
	if(x>k) {
		memset(visited,0,sizeof(visited));
		coun = 0;
		for(int i=1;i<=k;i++) {
			visited[n+i] = !citied[i];
			coun += int(citied[i]);
		}
		visited[1] = true;
		int rst = dfs(1,1);
		return rst;
	}
	int rst = search(x+1);
	citied[x] = true;
	rst = min(rst, c[x]+search(x+1));
	citied[x] = false;
	return rst;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	n = fastread();
	m = fastread();
	k = fastread();
	
	for(int i=1;i<=m;i++) {
		int u=fastread();
		int v=fastread();
		int weight=fastread();
		w[u][v] = weight;
		w[v][u] = weight;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	for(int i=1;i<=k;i++) {
		c[i] = fastread();
		for(int j=1;j<=n;j++) {
			a[i][j] = fastread();
		}
	}
	
	printf("%d",search(1));
	
	return 0;
}

/*
//	if(x<=k) {
//		for(int i=1;i<=n;i++) {
//			if(!visited[i]) {
//				visited[i] = true;
//				rst = min(rst, dfs(cnt+1,i)+c[x]+a[x][i]);
//				visited[i] = false;
//			}
//		}
//	}

inline int search(int x) {
	if(x>k) {
		memset(visited,0,sizeof(visited));
		visited[1] = true;
		return dfs(1,1);
	}
	search(x+1);	//不城市化
	 
	//备份 
	vector<pair<int,int>> backup_w;
	vector<int> backup_edge = move(edge[x]);
	for(int i=0,len=backup_edge.size();i<len;i++) {
		backup_w.push_back(make_pair(backup_edge[i],w[x][backup_edge[i]]));
	}
	//重建
	edge[x] = vector<int>();
	memset(w[x],0,sizeof(w[x]));
	
	//复原 
	edge = vector<int>();
	edge = move(backup);
	for(int i=0,len=backup_w.size();i<len;i++) {
		w[x][backup_w[i].first] = backup_w[i].second;
	}
}

//		printf("DFS:\n");
//		for(int i=1;i<=k;i++) {
//			printf("%d ",citied[i]);
//		}
//		printf("\n%d\n",rst);
*/
