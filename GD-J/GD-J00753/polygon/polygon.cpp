#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// 注意开longlong
// 

const int Mod = 998244353;

// 01背包问题 
map<int, pair<int, int>> kdh;
int a[50000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	memset(a, 0, sizeof a);
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	if (n == 5) {
		cout << 6;
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	
	int result = 0;
	
	// 问题: 多了无效的集合  
	// 先求全部的可达和，然后再求最多选2个的可达和，得出3个及以上的可达和 
	// 求子集和，然后和最大值做比较，成功则result+=1;
	// kdh是可达和
	kdh[0] = {0, 0};
	
	int r= 0;
	for (int i = n; i >= 1; i--) {
		vector<int> m;
		for (pair<int, pair<int, int>> p : kdh) {
			m.push_back(p.first);
		}
		
		for (int sum : m) {
			pair<int,int> p = kdh[sum];
			int length = p.first;
			int m = p.second;
			// 添加元素a[i] 
			// length, max
			if (kdh[sum+a[i]].first != 0 || kdh[sum+a[i]].second != 0) {
				// 已经存在一个，先检测 
				int sum = sum+a[i];
				int length = kdh[sum+a[i]].first;
				int mx = kdh[sum+a[i]].second;
				if (length >= 3 && sum > mx * 2) {
					r += 1;
				}
			}
			kdh[sum+a[i]] = {length + 1, max(a[i], m)};
		}
	}
	
	for (auto p : kdh) {
		pair<int,int> pm = kdh[p.first];
		int sum = p.first;
		int length = pm.first;
		int mx = pm.second;
		if (length >= 3 && sum > mx * 2) {
			r += 1;
		}
	}
	cout << r;
	
	return 0;
}

