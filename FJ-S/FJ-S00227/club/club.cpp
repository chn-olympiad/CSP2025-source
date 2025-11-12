#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

constexpr int N = 200005;

int T, n;
int d[N][6], t[N], cnt, ans;
vector<int> v[6];

inline int findg(int id){
	int a = d[id][1], b = d[id][2], c = d[id][3];
	if(a >= b && a <= c || a >= c && a <= b) return 1;
	if(b >= a && b <= c || b >= c && b <= a) return 2;
	if(c >= b && c <= a || c >= a && c <= b) return 3;
}

inline void Clear(){
	for (int i = 1; i <= n; i++){
		t[i] = d[i][1] = d[i][2] = d[i][3] = 0;
	}
	cnt = ans = 0;
	v[1].clear(); v[2].clear(); v[3].clear();
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--){
		Clear();
		cin >> n;
		for (int i = 1; i <= n; i++){
			int Max = -1, u = 0;
			for (int j = 1; j <= 3; j++){
				cin >> d[i][j];
				if(d[i][j] > Max) Max = d[i][j], u = j;
			}
			v[u].emplace_back(i);
			ans += d[i][u];
		}
		
		int u = 0;
		for (int i = 1; i <= 3; i++) u = v[i].size() > (n >> 1) ? i : u;
		
		if(u){
			for (int id : v[u]){
				int g = findg(id);
				t[++cnt] = d[id][u] - d[id][g];
			}
			
			sort(t + 1, t + cnt + 1);
			for (int i = 1; i <= v[u].size() - (n >> 1); i++){
				ans -= t[i];
			}
		}
		
		cout << ans << "\n";
	}
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
