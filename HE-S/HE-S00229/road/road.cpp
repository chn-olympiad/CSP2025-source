#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N = 1e4 + 10, M = 1e6 + 10;
typedef long long LL;
typedef pair<int, int> PII;

struct Edges{
	int a, b, c;
}e[M], e1[M];

bool cmp(Edges &a, Edges &b){
	return a.c < b.c;
}

int n, m, k;
int c[20], a[20][N];
int cost, cnt;
int p[N];
int ans = 1e18;
bool st[N];

int find(int x){
	if(p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void kruskal(int cntt){
	for(int i = 1 ; i <= n + cntt ; i ++){
		p[i] = i;
	}
	sort(e1 + 1, e1 + m + 1 + cnt, cmp);
	
	int sum = 0;
	for(int i = 1 ; i <= m + cnt ; i ++){
		int a = e1[i].a, b = e1[i].b, c = e1[i].c;
		a = find(a), b = find(b);
		if(a != b){
			p[a] = b;
			sum += c;
		}
	}
	ans = min(ans, cost + sum);
}

void dfs(int u){
	if(u > k){
		
		cnt = 0;
		cost = 0;
		
		for(int i = 1 ; i <= m ; i ++){
			e1[i] = e[i];
		}
		for(int i = 1 ; i <= k ; i ++){
			if(st[i]){
				cost += c[i];
				for(int j = 1 ; j <= n ; j ++){
					e1[m + (++ cnt)] = {n + 1, j, a[i][j]};
				}
			}
		}
		
		kruskal(u);
		return ;
	}
	st[u] = true;
	dfs(u + 1);
	st[u] = false;
	dfs(u + 1);
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

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin>>n>>m>>k;
	for(int i = 1 ; i <= m ; i ++){
		int a, b, c;
		cin>>a>>b>>c;
		e[i] = {a, b, c};
	}
	
	for(int i = 1 ; i <= k ; i ++){
		cin>>c[i];
		for(int j = 1 ; j <= n ; j ++){
			cin>>a[i][j];
		}
	}
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
}
