# include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 5;
const int N = 1e4 + 5;

int n, m, k;
int a[10][N];
int c[10];
int use[N];
int ans;
int build[10];
int build1[10][N];
int land;

struct Edge{
	int u, v, w;
}edge[M];

bool cmp (Edge A, Edge B){
	return A.w < B.w;
}

int main (){
	
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 0;i < m;i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	
	for (int i = 0;i < k;i++){
		cin >> c[i];
		
		for (int j = 0;j < n;j++){
			cin >> a[i][j];
		}
	}
	
	sort (edge, edge + m, cmp);
	
	for (int i = 0;i < m;i++){
		int temp = 0;
		for (int j = 0;j < k;j++){
			if (build[j] == 0){
				if (edge[i].w > c[j] + a[j][edge[i].u] + a[j][edge[i].v]){
					ans += c[j] + a[j][edge[i].u] + a[j][edge[i].v];
					build[j] = 1;
					build1[j][edge[i].u] = 1;
					build1[j][edge[i].v] = 1;
					use[edge[i].u] = 1;
					use[edge[i].v] = 1;
					temp = 1;
					//cout << "build:" << c[j] << " " << edge[i].u << " " << edge[i].v << "\n";
					land += 2;
				}
			}
			else {
				if (build1[j][edge[i].u] == 0 && build1[j][edge[i].v] == 0){
					if (edge[i].w > a[j][edge[i].u] + a[j][edge[i].v]){
						ans += a[j][edge[i].u] + a[j][edge[i].v];
						build1[j][edge[i].u] = 1;
						build1[j][edge[i].v] = 1;
						use[edge[i].u] = 1;
						use[edge[i].v] = 1;
						temp = 1;
						//cout << "build:" << c[j] << " " << edge[i].u << " " << edge[i].v << "\n";
						land += 2;
					}
				}
				else if (build1[j][edge[i].u] == 1 && build1[j][edge[i].v] == 0){
					if (edge[i].w > a[j][edge[i].v]){
						ans += a[j][edge[i].v];
						build1[j][edge[i].v] = 1;
						use[edge[i].u] = 1;
						use[edge[i].v] = 1;
						temp = 1;
						//cout << "build:" << c[j] << " " << edge[i].u << " " << edge[i].v << "\n";
						land += 1;
					}
				}
				else if (build1[j][edge[i].u] == 0 && build1[j][edge[i].v] == 1){
					if (edge[i].w > a[j][edge[i].u]){
						ans += a[j][edge[i].u];
						build1[j][edge[i].u] = 1;
						use[edge[i].u] = 1;
						use[edge[i].v] = 1;
						temp = 1;
						//cout << "build:" << c[j] << " " << edge[i].u << " " << edge[i].v << "\n";
						land += 1;
					}
				}
			}
		}
		if (temp == 1){
			continue;
		}
		if (!(use[edge[i].u] == 1 && use[edge[i].v] == 1)){
			ans += edge[i].w;
			use[edge[i].u] = 1;
			use[edge[i].v] = 1;
			//cout << "build:" << edge[i].u << " " << edge[i].v << "\n";
		}
	}
	
	cout << ans;
	
	return 0;
}
