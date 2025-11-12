#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

struct stu {
	int val;
	int id;
	
	bool operator < (const stu rhs) const {
		return val > rhs.val;
	}
};

struct P {
	int val;
	int id;
}temp[4];

struct cla {
	int st, nd, rd;
};

priority_queue<stu> q[4];

bool cmp(P x, P y) {
	return x.val > y.val;
}

const int N = 35;
int a[N], b[N], c[N], n, ans = 0;

void dfs(int x, int c1, int c2, int c3, int sum) {
	if (x == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	
	if (c1 < n / 2) {
		dfs(x + 1, c1 + 1, c2, c3, sum + a[x]);
	}
	if (c2 < n / 2) {
		dfs(x + 1, c1, c2 + 1, c3, sum + b[x]);
	}
	if (c3 < n / 2) {
		dfs(x + 1, c1, c2, c3 + 1, sum + c[x]);
	}
}

int main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		
		if (n <= 30) {
//			cout << "-------------" << endl;
			ans = 0;
			for (int i = 1; i <= n; ++i) {
				cin >> a[i] >> b[i] >> c[i];
			}
			dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
			continue;
		}
		
		vector <cla> a(n + 1); // 记录每一个人最喜欢的部门是哪一个 
		vector <cla> b(n + 1); // 记录每一个人最喜欢的部门的喜爱值 
		vector <int> kc(n + 1); // 记录一个人被开除的次数 
		
		for (int i = 1; i <= n; ++i) {
			cin >> temp[1].val >> temp[2].val >> temp[3].val;
			temp[1].id = 1; temp[2].id = 2; temp[3].id = 3;
			sort(temp + 1, temp + 4, cmp);
//			cout << temp[1].val << endl;
			a[i].st = temp[1].id; b[i].st = temp[1].val;
			a[i].nd = temp[2].id; b[i].nd = temp[2].val;
			a[i].rd = temp[3].id; b[i].rd = temp[3].val;
		}
		
		vector <int> cnt(4); // 记录当前部门的有多少人 
		int k = n / 2;
		
		for (int i = 1; i <= n; ++i) {
			
			int best = a[i].st; // 调查最喜欢的部门
			
			if (cnt[best] < k) { // 如果人数没有满 
				q[best].push({b[i].st, i});
				++cnt[best];
			} else { // 人数满了 
				int top = q[best].top().val;
				
				if (top < b[i].st) { //比参加当前部门的最小人的大 
					int tmp = q[best].top().id;
					q[best].pop();
					q[best].push({b[i].st, i});
					
					// 分配被开除的人
					// 可以用一个数组 kc 来记录这一个人被开除的次数，如果是第1次(kc数组等于0)，那么就可以找当前被开除的人第二喜欢的部门
					// 如果是第2次(kc数组等于1)被开除，就去找这个人第三喜欢的部门
					
					if (kc[tmp] == 0) {
						int last_id = a[tmp].nd; //找到第二喜欢的部门
						++cnt[last_id];
						q[last_id].push({b[tmp].nd, tmp});
						++kc[tmp];
					} else if (kc[tmp] == 1) {
						int last_id = a[tmp].rd;
						++cnt[last_id];
						q[last_id].push({b[tmp].rd, tmp});
						++kc[tmp];
					}
					
				} else if (top != b[i].st){
					int last_id = a[i].nd;
					++cnt[last_id];
					q[last_id].push({b[i].nd, i}); 
				}
			}
//			for (int i = 1; i <= 3; ++i) cout << cnt[i] << " ";
//			cout << endl;
		}
		
		ans = 0;
		while (!q[1].empty()) {
			ans += q[1].top().val;
			q[1].pop();
		}
		while (!q[2].empty()) {
			ans += q[2].top().val;
			q[2].pop();
		}
		while (!q[3].empty()) {
			ans += q[3].top().val;
			q[3].pop();
		}
		cout << ans << endl;
//		cout << endl;
	}
	
	return 0;
}