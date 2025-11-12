#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn][4], mx[maxn][4];
int cnt[4], pos[maxn];
bool cmp(const int &x, const int &y){
	if(mx[x][1] - mx[x][2] != mx[y][1] - mx[y][2]) return mx[x][1] - mx[x][2] > mx[y][1] - mx[y][2];
	if(mx[x][2] - mx[x][3] != mx[y][2] - mx[y][3]) return mx[x][2] - mx[x][3] > mx[y][2] - mx[y][3];
	return mx[x][1] > mx[y][1];
	//return x > y;
}
void init(){
	memset(a, 0, sizeof(a));
	memset(mx, 0, sizeof(mx));
	memset(cnt, 0, sizeof(cnt));
	memset(pos, 0, sizeof(pos));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		init();
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			multiset<int> st;
			st.insert(a[i][1]);
			st.insert(a[i][2]);
			st.insert(a[i][3]);
			auto it = st.begin();
			mx[i][3] = *it; it++;
			mx[i][2] = *it; it++;
			mx[i][1] = *it;
			pos[i] = i;
		}
		sort(pos + 1, pos + 1 + n, cmp);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int f = 0;
			int id = pos[i];
			for(int j = 1; j <= 3; j++){
				if(cnt[j] < n / 2 && a[id][f] < a[id][j]) f = j; 
			}
			ans += a[id][f], cnt[f]++;
		}
		cout << ans << endl;
	}
	return 0;
}
