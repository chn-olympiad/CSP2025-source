#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ro;
vector<vector<int>> road;
long long dij(int n, int begin, vector<vector<int>> &road){
	vector<bool> fixed(n + 5, false);
	int fi = 1;
	fi = begin;
	long long ans = 0;
	fixed[fi] = true;
	int v = 0;
	v = n;
	for(int i = 0; i < v; i ++){
		long long min_1 = -1, min_2 = fi;
		for(int l : road[fi]){
			if((min_1 > ro[fi][l] || min_1 < 0) && !fixed[l]){
				min_1 = ro[fi][l];
				min_2 = l;
			}
		}
		bool nex = false;
		if(min_2 == fi){
			nex = true;
		}
		if(nex){
			break;
		}
		ans += (min_1 == -1 ? 0 : min_1);
		fixed[min_2] = true;
		fi = min_2;
	}
	return ans;
}
long long bre(vector<int> &br, vector<vector<int>> &road, int times, int b_ans, int k, int &n){
	if(times > k){
		return dij(n + k, 1, road) + b_ans;
	}
	int vz = 0;
	vz = n;
	for(int y = 1; y <= vz; y ++){
		road[y].push_back(n + times);
		road[n + times].push_back(y);
	}
	long long u = bre(br, road, times + 1, b_ans + br[times], k, n);
	for(int y = 1; y <= vz; y ++){
		road[y].pop_back();
		road[n + times].pop_back();
	}
	long long v = bre(br, road, times + 1, b_ans, k, n);
	return min(u, v);
}
int main(){
	freopen("road1.in", "r", stdin);
	freopen("road1.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	ro.resize(n + k + 11, vector<int>(n + k + 11, INT_MAX - 1));
	road.resize(n + 5 + k);
	vector<int> br;
	br.resize(k);
	vector<vector<int>> brr;
	brr.resize(k + 1, vector<int>(n + 1, -1));
	for(int i = 1; i <= m; i ++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(ro[a][b] == INT_MAX - 1){
			road[a].push_back(b);
		}
		if(ro[b][a] == INT_MAX - 1){
			road[b].push_back(a);
		}
		ro[a][b] = min(ro[a][b], c);
		ro[b][a] = min(ro[b][a], c);
	}
	for(int i = 1; i <= k; i ++){
		scanf("%d", &br[i]);
		for(int y = 1; y <= n; y ++){
			scanf("%d", &brr[i][y]);
			ro[y][n + i] = brr[i][y];
			ro[n + i][y] = brr[i][y];
		}
	}
//	for(int i = 1; i <= n; i ++){
//		for(int y = 0; y < road[i].size(); y ++){
//			cout << road[i][y] << " ";
//		}
//		cout << endl;
//	}
//	cout << bre(br, road, 1, 0, k, n);
	cout << dij(n, 1, road);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
