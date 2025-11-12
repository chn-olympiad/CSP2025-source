#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

typedef unsigned long long data_t;

struct Comer {
	data_t a1, a2, a3;
	bool moved;
} a[100005];
//std::priority_queue<Comer> part[4];

// int val(Comer c) {
// 	if (c.moved) {
// 		if (c.a1>c.a2 && c.a2 > c.a3) {
// 			return c.a2-c.a3;
// 		} else if (c.a1>c.a3 && c.a3 > c.a2) {
// 			return c.a3-c.a2;
// 		} else if (c.a2>c.a3 && c.a3 > c.a1) {
// 			return c.a3-c.a1;
// 		} else if (c.a2>c.a1 && c.a1 > c.a3) {
// 			return c.a1-c.a3;
// 		} else if (c.a3 > c.a1 && c.a1 > c.a2) {
// 			return c.a1-c.a2;
// 		} else if (c.a3 > c.a2 && c.a2 > c.a1) {
// 			return c.a2-c.a1;
// 		}
// 	} else if (c.a1>c.a2 && c.a2 > c.a3) {
// 		return c.a1-c.a2;
// 	} else if (c.a1>c.a3 && c.a3 > c.a2) {
// 		return c.a1-c.a3;
// 	} else if (c.a2>c.a3 && c.a3 > c.a1) {
// 		return c.a2-c.a3;
// 	} else if (c.a2>c.a1 && c.a1 > c.a3) {
// 		return c.a2-c.a1;
// 	} else if (c.a3 > c.a1 && c.a1 > c.a2) {
// 		return c.a3-c.a1;
// 	} else if (c.a3 > c.a2 && c.a2 > c.a1) {
// 		return c.a3-c.a2;
// 	}
// }

bool cmp1(Comer lhs, Comer rhs) {
	return 2*lhs.a1-lhs.a2-lhs.a3 > 2*rhs.a1-rhs.a2-rhs.a3;
}

bool cmp2(Comer lhs, Comer rhs) {
	return 2*lhs.a2-lhs.a1-lhs.a3 > 2*rhs.a2-rhs.a1-rhs.a3;
}

bool cmp3(Comer lhs, Comer rhs) {
	return 2*lhs.a3-lhs.a2-lhs.a1 > 2*rhs.a3-rhs.a2-rhs.a1;
}

bool cmp4(Comer lhs, Comer rhs) {
	return abs(lhs.a1 - lhs.a2) > abs(rhs.a1 - rhs.a2);
}

// bool operator<(Comer lhs, Comer rhs) {
// 	return val(lhs) > val(rhs);
// }

data_t n;

data_t dfs(data_t p, data_t cnt1, data_t cnt2, data_t cnt3) {
	if(p > n) {
		return 0;
	}
	data_t max = 0;
	if (cnt1+1 <= n/2) {
		max = std::max(max, a[p].a1+dfs(p+1, cnt1+1, cnt2, cnt3));
	}
	if (cnt2+1 <= n/2) {
		max = std::max(max, a[p].a2+dfs(p+1, cnt1, cnt2+1, cnt3));
	}
	if (cnt3+1 <= n/2) {
		max = std::max(max, a[p].a3+dfs(p+1, cnt1, cnt2, cnt3+1));
	}
	return max;
}

void work() {
	scanf("%llu", &n);
	for (data_t i = 1 ; i <= n ; i ++) {
		scanf("%llu%llu%llu", &a[i].a1, &a[i].a2, &a[i].a3);
		// if (a[i].a1>a[i].a2 && a[i].a1 > a[i].a3) {
		// 	part[1].push(a[i]);
		// } else if (a[i].a2>a[i].a3 && a[i].a2 > a[i].a1) {
		// 	part[1].push(a[i]);
		// } else if (a[i].a3>a[i].a2 && a[i].a1 < a[i].a3) {
		// 	part[1].push(a[i]);
		// }
	}
	if (n <= 10) {
		printf("%llu\n", dfs(1, 0, 0, 0));
		return ;
	}
	std::sort(a+1, a+n+1, cmp4);
	data_t score = 0, cnt1 = 0, cnt2 = 0;
	for (data_t i = 1 ; i <= n ; i ++) {
		if (cnt1+1 > n/2) {
			cnt2++;
			score += a[i].a2;
		} else if (cnt2+1 > n/2) {
			cnt1++;
			score += a[i].a1;
		} else if (a[i].a1 > a[i].a2) {
			cnt1 ++;
			score += a[i].a1;
		} else if (a[i].a1 < a[i].a2) {
			cnt2++;
			score += a[i].a2;
		} else if (cnt1 < cnt2) {
			cnt1++;
			score += a[i].a1;
		} else {
			cnt2++;
			score += a[i].a2;
		}
	}
	printf("%llu\n", score);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0 ; i < t ; i ++) {
		work();
	}
	return 0;
}
