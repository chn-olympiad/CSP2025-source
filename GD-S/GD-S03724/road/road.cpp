#include <bits/stdc++.h>
using namespace std;

int n, m, k, fa[10005], pathsum;
unsigned long long ans;
unsigned long long cre[10005][15], c[15];
vector <unsigned long long> neww[15];
vector <pair<unsigned long long, pair<int, int>>> usedd;
struct ss{
	int a, b;
	unsigned long long w;
}path[1000005];

bool cmp(ss xx, ss yy){
	return xx.w < yy.w;
}

int getfa(int son){
	if (fa[son] = son)	return fa[son];
	return getfa(fa[son]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u, v;
	unsigned long long w;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		path[i].a = u;
		path[i].b = v;
		path[i].w = w;
	}
	unsigned aaa;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> aaa;
			neww[j].push_back(aaa);
		}
	}
	sort(path+1, path+1+m, cmp);
	for (int i = 1; i <= n; i++)	fa[i] = i;
	for (int i = 1; i <= m; i++){
		if (getfa(path[i].a) != getfa(path[i].b)){
			usedd.push_back({path[i].w, {path[i].a, path[i].b}});
			fa[path[i].a] = fa[path[i].b];
			pathsum++;
			if (pathsum == n-1)	break;
		}
	}
	for (int i = 0; i < pathsum; i++){
		w = usedd[i].first, u = usedd[i].second.first, v= usedd[i].second.second;
		ans += w;
	}
	if (k == 0){
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= k; i++){
		for (int j = 0; j < pathsum; j++){
			w = usedd[j].first, u = usedd[j].second.first, v= usedd[j].second.second;
			if (w > neww[i][u]+neww[i][v]){
				cre[j][i] = w-(neww[i][u]+neww[i][v]);
			}
			else{
				cre[j][i] = 0;
			}
		}
	}
	bool flag[15];
	for (int i = 0; i < (1<<k); i++){
		int kk = i;
		memset(flag, 0, 15);
		int f = 1;
		unsigned long long summ = 0;
		while (kk > 0){
			if (kk%2 == 1){
				flag[f] = true;
				summ += c[f];
			}
			f++;
			kk /= 2;
		}
		for (int j = 0; j < pathsum; j++){
			w = usedd[j].first, u = usedd[j].second.first, v= usedd[j].second.second;
			unsigned long long jss = 0;
			for (int l = 1; l <= k; l++){
				if (flag[l] == true)	jss = max(jss, cre[j][l]);
			}
			int bian = w-jss;
			summ += bian;
		}
		ans = min(ans, summ);
	}
	cout << ans;
	return 0;
}
