#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int T, n, Maxn[N], sec[N], ans;
struct Node {
	int val[3];
} p[N];
vector<int> Team[N];
bool cmpT(vector<int> x, vector<int> y) {
	return x.size() > y.
	
	size();
}
bool cmpP(int x, int y) {
	return (Maxn[x] - sec[x]) < (Maxn[y] - sec[y]);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> T;
	while (T --) {
		cin >> n, ans = 0;
		for (int i = 0; i < 3; i ++) Team[i].clear();
		for (int i = 1; i <= n; i ++) {
			cin >> p[i].val[0] >> p[i].val[1] >> p[i].val[2];
			Node tmp = p[i];
			sort(tmp.val, tmp.val + 3);
			sec[i] = tmp.val[1];
		}
		for (int i = 1; i <= n; i ++) {
			int Max = max({p[i].val[0], p[i].val[1], p[i].val[2]});
			Maxn[i] = Max;
			bool flag = 0;
			for (int j = 0; j < 3; j ++) {
				if (Max == p[i].val[j] && !flag) Team[j].push_back(i), flag = 1; 
			}
		}
		sort(Team, Team + 3, cmpT);
		if (Team[0].size() <= (n >> 1)) {
			for (int i = 1; i <= n; i ++) ans += Maxn[i];
		} else {
			for (int i = 1; i < 3; i ++) {
				for (int v : Team[i]) ans += Maxn[v];
			}
			sort(Team[0].begin(), Team[0].end(), cmpP);
			int siz = Team[0].size();
			for (int v : Team[0]) {
				if (siz > (n >> 1)) ans += sec[v], siz --;
				else ans += Maxn[v];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*
二、阅读理解 
________________17:50______________________ 
屏幕前的家人们，你们觉得我今年有√~~7~~6吗 

________________18:13______________________
666还有互动环节，我被资本做局了你知道吗2333 

________________18:27______________________
别发电了，不会有人给你点亮小红心的。 

________________18:30______________________
555，会有的，诶不好老刂 

(1).(400pts) 
---- What time is it now? 
(2).(-400pts)
----  作者为什么说不好


___________________________________________
总之
 
又是我，

我要上迷惑行为大赏！！！还有伊蕾娜我老婆 

Luogu: OIerElaina
*/
