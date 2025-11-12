#include<bits/stdc++.h>

using namespace std;

struct abc{
	int ma1, ma2;
	int g, h;
}a[100001];

int t, n;
int ans = -1;
int ff[100001];

void dfs(int g, int q, int w, int e, int c){
	if (g == n){
		ans = max(ans, c);
		return ;
	}
//	cout << c << ' ';
	if (a[g].g == 1 && q < n / 2){
		dfs(g + 1, q + 1, w, e, c + a[g].ma1);
	}
	if (a[g].g == 2 && w < n / 2){
		dfs(g + 1, q, w + 1, e, c + a[g].ma1);
	}
	if (a[g].g == 3 && e < n / 2){
		dfs(g + 1, q, w, e + 1, c + a[g].ma1);
	}
	
	if (a[g].h == 1 && q < n / 2){
		dfs(g + 1, q + 1, w, e, c + a[g].ma2);
	}
	if (a[g].h == 2 && w < n / 2){
		dfs(g + 1, q, w + 1, e, c + a[g].ma2);
	}
	if (a[g].h == 3 && e < n / 2){
		dfs(g + 1, q, w, e + 1, c + a[g].ma2);
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		int f[11];
		cin >> n;
		for(int i = 0; i < n; i++){
			int q, w, e, g[11], h[11];
			ff[i] = 0;
			cin >> q >> w >> e;
			g[1] = q; g[2] = w; g[3] = e;
			h[1] = 1; h[2] = 2; h[3] = 3;
			if (g[2] > g[3]){
				swap(g[2], g[3]);
				swap(h[2], h[3]);
			}
			if (g[1] > g[2]){
				swap(g[1], g[2]);
				swap(h[1], h[2]);
			}
			if (g[2] > g[3]){
				swap(g[2], g[3]);
				swap(h[2], h[3]);
			}
			a[i].ma1 = g[3];
			a[i].g = h[3];
			a[i].ma2 = g[2];
			a[i].h = h[2];
//			cout << '\n';
//			cout << a[i].ma1 << ' ' << a[i].g << '\n';
//			cout << a[i].ma2 << ' ' << a[i].h << '\n' << '\n';
		}
		ans = 0;
		dfs(0,0,0,0,0);
		cout << ans << '\n';
	}
}
