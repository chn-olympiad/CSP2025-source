//#include <bits/stdc++.h>
//
//using namespace std;
//
//int t, n, diff[100005][5][5], sum, siz[5], tmp[100005][5];
//
//struct node {
//	int val, id;
//} a[100005][5]; 
//
//bool cmp(node a, node b) {
//	return a.val > b.val; 
//} 
//
///*
//
//1. 要让 club 的总分加起来最大
//2. 不可以超过 n / 2
//3. 若大于 n / 2，让换到另外一个贡献最少的交换
//
//1. 优先加入满足度最大的 
//
//3. 若 minn > 当前数换到别的地方的 minn，则将当前数换到别的部门
//4. 否则，将当前数加入最优的部门，换走 minn 所在的部门 
//
//*/
//
//void work(int x) {
//	int id1 = a[x][1].id, id2 = a[x][2].id, id3 = a[x][3].id; // 表示部门按满意度排名后的第一名。。。
//	int VAL = 1e9, TYPE = 0, ID = 0;
//	for (int i = 2; i <= 3; i++) {
//		int v = a[x][1].val - a[x][i].val;
//		if (v < VAL) {
//			if (siz[a[x][i].id] < n / 2) {
//				VAL = v, TYPE = a[x][i].id, ID = i; 
//			}
//		}
//	}
//	if (siz[id1] < n / 2) {
//		tmp[++siz[id1]][id1] = x;
//		sum += a[x][1].val;
//	} else {
//		// 2. 若不能加入，则在该部门寻找一个换到别的部门减掉的最少的 minn 
//		int Min = 1e9, Type = 0, Id = 0, iid = 0; // Min 是找到的最小贡献、对应的部门下标、在该部门下标、在数组中下标 
//		for (int j = 1; j <= siz[id1]; j++) {
//			// 应该先找到 id1 部对应的在 a[tmp[j][id1] 的编号
//			int pos = 0; // 编号 
//			for (int k = 1; k <= 3; k++) { // 排名 
//				if (a[tmp[j][id1]][k].id == id1) {
//					pos = k;
//					break;
//				}
//			} 
//			int X1 = a[tmp[j][id1]][pos].val;
////						cout << "111:" << X1 << '\n';
//			int minn = 1e9, type = 0, id = 0; // type 是 club 编号，id 是找到的下标 
//			for (int k = 1; k <= 3; k++) {
//				int nowid = a[tmp[j][id1]][k].id; // 当前对应 club 的编号 
//				if (nowid != id1) { // 找到其他的 club 了 
//					int X2 = a[tmp[j][id1]][k].val;
//					int bet = X1 - X2;
//					if (bet < minn) {
//						if (siz[nowid] < n / 2) {
//							minn = bet;
//							type = nowid;
//							id = k;
//						}
//					}
//				}
//			}
//			if (minn < Min) {
////				cout << id << '\n';
//				Min = minn;
//				Type = type;
//				Id = tmp[j][id1];
//				iid = id;
//			}
//		}
//		if (Min > VAL) {
//			tmp[++siz[TYPE]][TYPE] = x;
//			sum += a[x][ID].val;
//		} else {
//			tmp[++siz[Type]][Type] = tmp[Id][id1];
//			int pos = 0;
//			for (int k = 1; k <= 3; k++) {
//				if (a[Id][k].id == id1) {
//					pos = k;
//					break;
//				}
//			}
////			cout << "Val:" << tmp[Id][id1] << '\n';
//			sum -= a[tmp[Id][id1]][pos].val, sum += a[tmp[Id][Type]][iid].val;
//			tmp[Id][id1] = x;
//			sum += a[x][1].val;
//		}
//	}
//}
//
//void work() {
//	sum = 0;
//	memset (tmp, 0, sizeof tmp);
//	memset (siz, 0, sizeof siz);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][1].val >> a[i][2].val >> a[i][3].val;
//		a[i][1].id = 1, a[i][2].id = 2, a[i][3].id = 3;
//		sort (a[i] + 1, a[i] + 1 + n, cmp);
////		for (int j = 1; j <= 3; j++) {
////			for (int k = j + 1; k <= 3; k++) {
////				diff[i][j][k] = a[i][j].val - a[i][k].val;
////			} 
////		}
//	}
//	for (int i = 1; i <= n; i++) {
//		work(i);
////		cout << sum << '\n';
//	}
//	cout << sum << "\n";
//}
//
//signed main() {
//	freopen("club2.in", "r", stdin);
//	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	cin >> t;
//	while (t--)
//		work();
//	return 0;
//} 
//
///*
//
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//
//18
//4
//13
//
//
//
//1
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//
//
//1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//
//*/
#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005][3], maxn, A[100005];

void dfs(int cur, int cnta, int cntb, int cntc, int sum) {
	if (cur == n + 1) {
		maxn = max(maxn, sum);
		return;
	}
	if (cnta < n / 2) {
		dfs(cur + 1, cnta + 1, cntb, cntc, sum + a[cur][1]);
	}
	if (cntb < n / 2) {
		dfs(cur + 1, cnta, cntb + 1, cntc, sum + a[cur][2]);
	}
	if (cntc < n / 2) {
		dfs(cur + 1, cnta, cntb, cntc + 1, sum + a[cur][3]);
	}
}

void work() {
	maxn = 0;
	int cnt2 = 0, cnt3 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		A[i] = a[i][1];
		cnt2 += (a[i][2] == 0);
		cnt3 += (a[i][3] == 0);
	}
	if (cnt2 == n && cnt3 == n) {
		int sum = 0;
		sort (A + 1, A + 1 + n, greater<int>());
		for (int i = 1; i <= n / 2; i++) {
			sum += A[i];
		}
		cout << sum;
		return;
	}
	dfs(1, 0, 0, 0, 0);
	cout << maxn << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
		work();
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

18
4
13



1
4
4 2 1
3 2 4
5 3 4
3 5 1


1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
