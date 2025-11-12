#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

constexpr int MAXN = 1e5 + 10;

int n;
struct Student {
	std::array<std::pair<int, int>, 3> like;
	
	Student() : like() {}
	Student(int a, int b, int c) {
		like[0] = std::make_pair(a, 0);
		like[1] = std::make_pair(b, 1);
		like[2] = std::make_pair(c, 2);
	}

	int find(int now) {
		for(int i = 2; i >= 0; i--) {
			if(like[i].second == now) {
				return i;
			}
		}
		return 0;
	}
	int less(int now) {
		now = find(now);
		if(now == 0) return 1e9+7;
		return like[now].first-like[now-1].first;
	}
};
std::array<Student, MAXN> a;

void input() {
	scanf("%d", &n);
	int u, v, w;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		a[i] = Student(u, v, w);
	}
}

namespace AC {

void work() {
	for(int i = 1; i <= n; i++) {
		std::sort(a[i].like.begin(), a[i].like.end());
	}
	std::array<std::vector<Student>, 3> set;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		set[a[i].like[2].second].push_back(a[i]);
		ans += a[i].like[2].first;
	}
	while(set[0].size() > n/2 || set[1].size() > n/2 || set[2].size() > n/2) {
		for(int i = 0; i < 3; i++) {
			if(set[i].size() <= n/2) continue;
			std::sort(set[i].begin(), set[i].end(), [&](Student& a, Student& b) {
				return a.less(i) > b.less(i);
			});
			while(set[i].size() > n/2) {
				Student top = set[i].back();
				set[i].pop_back();
				ans -= top.less(i);
				set[top.like[top.find(i)-1].second].push_back(top);
			}
		}
	}
	printf("%lld\n", ans);
}

};

namespace BAOLI {

long long ans;

void Dfs(int now, int cnt1, int cnt2, int cnt3, long long sum) {
	if(now == n+1) {
		ans = std::max(ans, sum);
		return ;
	}
	if(cnt1 < n/2) Dfs(now+1, cnt1+1, cnt2, cnt3, sum+a[now].like[0].first);
	if(cnt2 < n/2) Dfs(now+1, cnt1, cnt2+1, cnt3, sum+a[now].like[1].first);
	if(cnt3 < n/2) Dfs(now+1, cnt1, cnt2, cnt3+1, sum+a[now].like[2].first);
}

void work() {
	ans = 0;
	Dfs(1, 0, 0, 0, 0);
	printf("%lld\n", ans);
}

};

void work() {
	if(n <= 10) BAOLI::work();
	else {
		AC::work();
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		input();
		work();
	}
	return 0;
}
