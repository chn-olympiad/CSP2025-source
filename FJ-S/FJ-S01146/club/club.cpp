#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 20;

int T;

int n;
int a[N][4], ans;

int t, _;
set<int> club[4];

struct Node{
	int u, v;
	int val, _;
	
	bool operator <(const Node &b) const{
		return val < b.val;
	}
};
priority_queue<Node> q;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	ans = _ = t = 0;
	club[1].clear(), club[2].clear(), club[3].clear();
	
	n = read();
	for(int i = 1; i <= n; ++i){
		int f = 1;
		for(int j = 1; j <= 3; ++j){
			a[i][j] = read();
			if(a[i][f] < a[i][j]) f = j;
		}
		ans += a[i][f];
		club[f].insert(i);
	}
	for(int i = 1; i <= 3; ++i){
		if(club[i].size() > n / 2){
			for(auto k : club[i]){
				if(i != 1) q.push({i, 1, a[k][1] - a[k][i], k});
				if(i != 2) q.push({i, 2, a[k][2] - a[k][i], k});
				if(i != 3) q.push({i, 3, a[k][3] - a[k][i], k});
			}
			_ = t = i;
			break;
		}
	}
	while(!q.empty() && club[t].size() > n / 2){
		int u = q.top().u, v = q.top().v, res = q.top().val, k = q.top()._;
		q.pop();
		if(club[u].find(k) == club[u].end()) continue;
		club[u].erase(k), club[v].insert(k);
		ans += res;
	}
	while(!q.empty()) q.pop();
	
	t = 0;
	for(int i = 1; i <= 3; ++i)
		if(club[i].size() > n / 2){
			for(auto k : club[i]){
				if(i != 1 && _ != 1) q.push({i, 1, a[k][1] - a[k][i], k});
				if(i != 2 && _ != 2) q.push({i, 2, a[k][2] - a[k][i], k});
				if(i != 3 && _ != 3) q.push({i, 3, a[k][3] - a[k][i], k});
			}
			t = i;
			break;
		}
	while(!q.empty() && club[t].size() > n / 2){
		int u = q.top().u, v = q.top().v, res = q.top().val, k = q.top()._;
		q.pop();
		if(club[u].find(k) == club[u].end()) continue;
		club[u].erase(k), club[v].insert(k);
		ans += res;
	}
	while(!q.empty()) q.pop();
	
	printf("%lld\n", ans);
	
	return;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	T = 1;
	T = read();
	while(T--)
		solve();
	return 0;
}

/*

10 9 8
4 0 0

必然只有一个超过n/2
*/
