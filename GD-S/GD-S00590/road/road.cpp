#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;

int tw[10005];
int eds[5005][5005];
bool cnt[10005];

struct p{
	int cst, dsn;
};
bool cmp(p x, p y){
	return x.cst < y.cst;
}

vector<p> a;

signed main(){

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset (eds, 0x3f, sizeof(eds));
	for(int i = 1; i <= n; i++) eds[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int tu, tv, tw;
		cin >> tu >> tv >> tw;
		eds[tu][tv] = tw;
		eds[tv][tu] = tw;
	}
	
	for(int i = 1; i <= k; i++){
		int tcost;
		cin >> tcost;
		for(int j = 1; j <= n; j++){
			cin >> tw[i];
			for(int jj = 1; jj < j; jj++)
				eds[jj][j] = eds[j][jj] = min(eds[j][jj], tw[j] + tw[jj] + tcost);

		}
	}
	
	int ans = 0, curr = 1, ct = 1;
	while(1){
		int mn = LONG_LONG_MAX;
		for(int i = 1; i <= n; i++)
				a.push_back({eds[curr][i], i});
		
		if(ct++ > n) break;
		p nxt;
		sort(a.rbegin(), a.rend(), cmp);
		do{
			nxt = a.back();
			a.pop_back();
		} while(cnt[nxt.dsn]);
		curr = nxt.dsn;
		cnt[curr] = 1;
		ans += nxt.cst;
	}
	
	cout << ans;
	return 0;
} 

