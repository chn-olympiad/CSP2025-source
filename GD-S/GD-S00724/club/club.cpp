# include <bits/stdc++.h>
# define pb push_back
//# define int long long
using namespace std;

const int N = 1e5 + 5;

int n, cnt, arr[N][5];

vector <int> v[4];

void solve(){
	v[1].clear(); v[2].clear(); v[3].clear();
	scanf("%d", &n); cnt = 0;
	int ans = 0;
	for (int i = 1, x;i <= n;i++){
		scanf("%d%d%d", &arr[i][1], &arr[i][2], &arr[i][3]); ans += max(max(arr[i][1], arr[i][2]), arr[i][3]);
		if (arr[i][1] >= arr[i][2] && arr[i][1] >= arr[i][3]) v[1].pb(i);
		if (arr[i][2] >= arr[i][1] && arr[i][2] >= arr[i][3]) v[2].pb(i);
		if (arr[i][3] >= arr[i][1] && arr[i][3] >= arr[i][2]) v[3].pb(i);
		sort (arr[i]+1, arr[i]+4);
	}
	int t = 0;
	if ((int)v[1].size() > n/2) t = 1; 
	if ((int)v[2].size() > n/2) t = 2; 
	if ((int)v[3].size() > n/2) t = 3;
	int cha = (int)v[t].size() - n / 2;
	vector <int> tmp;
	for (int i : v[t]) tmp.pb(arr[i][3] - arr[i][2]);
	sort (tmp.begin(), tmp.end());
	for (int i = 0;i < cha;i++) ans -= tmp[i];
	printf("%d\n", ans);
}

int main(){
	freopen("club.in",  "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("my.txt", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

