#include <iostream>
#include <algorithm>
using namespace std;

struct Line{
	int u;//smaller node
	int v;//greater node
	long int w;//weigh
	int i;//through village, -1 for not
};

bool Sorter(Line a, Line b){
	if(a.w < b.w)return 1;
	else if(a.w > b.w) return 0;
	else return 1;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long int n, m, k;
	cin >> n >> m >> k;
	long long int V[k][n], VS[k];//value of each village to each city; value of village itself
	long long int L[n];//lian tong fen liang
	Line l[m+(n*n-n)/2];
	bool R[k];//is village rebuild
	//create Graph
	for(long long int i = 0; i < n; i++)L[i] = i;
	for(long long int i = 0; i < m; i++){
		long long int u, v, w;
		cin >> u >> v >> w;
		if(u < v)l[i].u = u-1, l[i].v = v-1, l[i].w = w, l[i].i = -1;
		else l[i].u = v-1, l[i].v = u-1, l[i].w = w, l[i].i = -1;
	}
	for(long long int i = 0; i < k; i++){
		cin >> VS[i];
		R[i] = 0;
		for(long long int j = 0; j < n; j++)cin >> V[i][j];
	}
	long long int tmp = m;
	for(long long int i = 0; i < n; i++){//set other lines
		for(long long int j = i+1; j < n; j++){
			l[tmp].u = i, l[tmp].v = j, l[tmp].i = -1, l[tmp].w = 3000000010;
			for(long long int g = 0; g < k; g++){
				if(V[g][i] + V[g][j] + VS[g] < l[tmp].w){
					l[tmp].w = V[g][i] + V[g][j] + VS[g];
					l[tmp].i = g;
				}
			}
			tmp++;
		}
	}
	//done input (above), using Kruskal now(below)
	long long int ans = 0;
	for(long long int i = 0; i < n-1; i++){//i for finding path
		sort(l, l+m+(n*n-n)/2, Sorter);
		for(long long int j = 0; j < m+(n*n-n)/2; j++){//go through the lines
			long long int tmpa = L[l[j].u], tmpb = L[l[j].v];
			if(tmpa != tmpb){//found the one
				ans += l[j].w;
				for(long long int g = 0; g < n; g++)if(L[g] == tmpb)L[g] = tmpa;//combine two LTFL
				if(l[j].i != -1 && R[l[j].i] == 0){
					for(long long int o = 0; o < m+(n*n/2)+n; o++){
						if(l[o].i == l[j].i)l[o].w -= VS[l[j].i];
						R[l[j].i] = 1;
					}
				}
				break;//buggy thing
			}
		}
	}
	cout << ans;
	return 0;
}
