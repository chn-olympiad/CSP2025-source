#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int u, v, w;
	friend bool operator < (const node& a, const node& b) {
		return a.w > b.w;
	}
};


const int maxn = 2e4 + 100, maxk = 15;
int fath[maxn];

int find(int x) {
	if(fath[x] == x)
		return x;
	return fath[x] = find(fath[x]);
}

bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	
	if(fx == fy)
		return false;
	
	fath[fx] = fy;
	return true; 
}

int kruskal(int n, priority_queue<node> qp) {
	
	for(int i = 1; i <= n; i ++)
		fath[i] = i;
	
	priority_queue<node> cop_;
	int cnt = n, ans = 0;
	
	while(cnt > 1 && !qp.empty()) {
		
		//cout << ans << endl;
		
		node cur = qp.top();
		qp.pop();
		
		if(merge(cur.u, cur.v)) cnt --, ans += cur.w;
		
		cop_.push(cur);
	}
	
	while(!cop_.empty()) {
		
		qp.push(cop_.top());
		cop_.pop();
	}
	
	return ans;
}

int n, m, k;

vector<pair<int,int> > edge[maxn], nxt[maxk];
int jz[maxn];

priority_queue<node> qp, cop_;

priority_queue<node> cop(priority_queue<node> p) {
	return p;
}

void addedge(int x) {
	//cout << 1 << endl;
	for(int i = 0; i < nxt[x].size(); i ++) {
		//cout << x << ' ' << nxt[x][i].first << endl; 
		cop_.push({nxt[x][i].first , x + n, nxt[x][i].second});
	}

}

int ans = INT_MAX;

void dfs(int now, int zt, int cmt) {
	if(now == k + 1) {
		//cout << cmt << ' ' << zt << endl;

		int count = 0;
		
		cop_ = cop(qp);
		
		for(int i = 1; i <= k; i ++) {
			if(zt & (1 << i)) {
				//cout << i << endl;
				addedge(i);
				count ++;
			}
			
		}
		
//		while(!cop_.empty()) {
//			cout << cop_.top().u << ' ' << cop_.top().v << ' ' << cop_.top().w << endl;
//			cop_.pop();
//		} 
//		
//		cout << endl;
		
		ans = min(cmt + kruskal(count + n, cop_), ans);
		return ;
	}
	dfs(now + 1, zt, cmt);
	dfs(now + 1, zt + (1 << now), cmt + jz[now]);
}

signed main() {
    freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge[x].push_back({y, w});
		edge[y].push_back({x, w});
		qp.push({x, y, w});
	}
	
	int dec = 0; 
	
	for(int i = 1; i <= k; i ++) {
		cin >> jz[i];
		
		if(jz[i])
			dec = 1;
			
		for(int j = 1; j <= n; j ++) {
			int w;
			cin >> w;
			nxt[i].push_back({j, w});
			
			if(w)
				dec = 1;
		}
	}
	
	if(!dec && k) {
		cout << 0;
		return 0;
	}
	else {
		dfs(1, 0, 0);
	}
	
	cout << ans;
	
	return 0;
}
/*
3 3 2
1 2 1
1 3 1
2 3 1
0 0 0 0
0 0 0 0
*/

