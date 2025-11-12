/*
 * @file club.cpp
 * @author HN-S00799
*/
#include <bits/stdc++.h>
#define file(s) \
	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)

using i64 = long long;
using ull = unsigned long long;
using i28 = __int128;
using f32 = double;
using ldb = long double;

inline int read() {
	register int x = 0, sgn = 1;
	register char ch = getchar_unlocked();
	while(!isdigit(ch)) {
		if (ch == '-') {
			sgn = -1;
			ch = getchar_unlocked();
		}
	}
	while (isdigit(ch)) {
		x *= 10;
		x += ch - '0';
		ch = getchar_unlocked();
	}
	return x * sgn;
}

constexpr int N = 1e5 + 5;
// int a[N][5];

// struct stu{
// 	int a, b, c;
// };

// // const bool operator > (const stu P, const stu Q) {
// // 	int minp = std::min(P.a, std::min(P.b, P.c)), minq = std::min(Q.a, std::min(Q.b, Q.c));
// // 	if (minp != minq) {
// // 		return minp < minq;
// // 	} 
// // 	// return std::max(P.a, std::max(P.b, P.c)) < std::max(Q.a, std::max(Q.b, Q.c));
// // 	if (P.a != Q.a) {
// // 		return P.a > Q.a;
// // 	}
// // 	if (P.b != Q.b) {
// // 		return P.b > Q.b;
// // 	}
// // 	if (P.c != Q.c) {
// // 		return P.c > Q.c;
// // 	}
// // 	return 0;
// // }

// int t;
// std::vector<stu>a;
// bool cmpa(stu P, stu Q) {
// 	if (P.a != Q.a) {
// 		return P.a > Q.a;
// 	}
// 	int midp, midq;
// 	if (P.a >= P.b && P.b >= P.c) {
// 		midp = P.b;
// 	} else if (P.a <= P.b && P.a >= P.c) {
// 		midp = P.a;
// 	} else {
// 		midp = P.c;
// 	}
// 	if (Q.a >= Q.b && Q.b >= Q.c) {
// 		midq = Q.b;
// 	} else if (Q.a <= Q.b && Q.a >= Q.c) {
// 		midq = Q.a;
// 	} else {
// 		midq = Q.c;
// 	}
// 	return midp < midq;
// }
// bool cmpb(stu P, stu Q) {
// 	if (P.b != Q.b) {
// 		return P.b > Q.b;
// 	}
// 	int midp, midq;
// 	if (P.a >= P.b && P.b >= P.c) {
// 		midp = P.b;
// 	} else if (P.a <= P.b && P.a >= P.c) {
// 		midp = P.a;
// 	} else {
// 		midp = P.c;
// 	}
// 	if (Q.a >= Q.b && Q.b >= Q.c) {
// 		midq = Q.b;
// 	} else if (Q.a <= Q.b && Q.a >= Q.c) {
// 		midq = Q.a;
// 	} else {
// 		midq = Q.c;
// 	}
// 	return midp < midq;
// }
// bool cmpc(stu P, stu Q) {
// 	if (P.c != Q.c) {
// 		return P.c > Q.c;
// 	}
// 	int midp, midq;
// 	if (P.a >= P.b && P.b >= P.c) {
// 		midp = P.b;
// 	} else if (P.a <= P.b && P.a >= P.c) {
// 		midp = P.a;
// 	} else {
// 		midp = P.c;
// 	}
// 	if (Q.a >= Q.b && Q.b >= Q.c) {
// 		midq = Q.b;
// 	} else if (Q.a <= Q.b && Q.a >= Q.c) {
// 		midq = Q.a;
// 	} else {
// 		midq = Q.c;
// 	}
// 	return midp < midq;
// 	// int minp = std::min(P.a, std::min(P.b, P.c)), minq = std::min(Q.a, std::min(Q.b, Q.c));
// 	// if (minp != minq) {
// 	// 	return minp < minq;
// 	// } 
// }
// bool cmpa1(stu x, stu y) {
// 	return std::max(x.b, x.c) > std::max(y.b, y.c);
// }
// bool cmpb1(stu x, stu y) {
// 	return std::max(x.a, x.c) > std::max(y.a, y.c);
// }
// bool cmpc1(stu x, stu y) {
// 	return std::max(x.a, x.b) > std::max(y.a, y.b);
// }

// void work() {
// 	int n = read();
// 	stu tmp;
// 	int popa = 0, popb = 0, popc = 0;
// 	i64 ans = 0;
// 	for (int i = 1; i <= n; i++) {
// 		tmp = {read(), read(), read()};
// 		a.push_back(tmp);
// 		if (tmp.a >= tmp.b && tmp.a >= tmp.c) {
// 			popa++;
// 			ans += tmp.a;
// 			// printf("%d %d\n", popa, ans);
// 		} else if (tmp.b >= tmp.c && tmp.b >= tmp.a) {
// 			popb++;
// 			ans += tmp.b;
// 			// printf("%d %d\n", popb, ans);
// 		} else {
// 			popc++;
// 			ans += tmp.c;
// 			// printf("%d %d\n", popc, ans);
// 		}
// 	}
// 	if (popa <= (n >> 1) && popb <= (n >> 1) && popc <= (n >> 1)) {
// 		printf("%lld\n", ans);
// 		return ;
// 	}
// 	ans = 0;
// 	int cnt = 0;
// 	if (popa > (n >> 1)) {
// 		std::sort(a.begin(), a.end() - 1, cmpa);
// 		for (auto it = a.begin(); it != a.end(); ++it) {
// 			cnt++;
// 			if (cnt < (n << 1)) {
// 				tmp = *it;
// 				ans += tmp.a;
// 				*it = {0, 0, 0};
// 			} else {
// 				break;
// 			}
// 		}
// 		std::sort(a.begin(), a.end(), cmpa1);
// 		for (stu j:a) {
// 			ans += std::max(j.b, j.c);
// 		}
// 	}
// 	if (popb > (n >> 1)) {
// 		std::sort(a.begin(), a.end() - 1, cmpb);
// 		for (auto it = a.begin(); it != a.end(); ++it) {
// 			cnt++;
// 			if (cnt < (n << 1)) {
// 				tmp = *it;
// 				ans += tmp.b;
// 				*it = {0, 0, 0};
// 			} else {
// 				break;
// 			}
// 		}
// 		std::sort(a.begin(), a.end(), cmpb1);
// 		for (stu j:a) {
// 			ans += std::max(j.a, j.c);
// 		}
// 	}
// 	if (popc > (n >> 1)) {
// 		std::sort(a.begin(), a.end() - 1, cmpc);
// 		for (auto it = a.begin(); it != a.end(); ++it) {
// 			cnt++;
// 			if (cnt < (n << 1)) {
// 				tmp = *it;
// 				ans += tmp.c;
// 				*it = {0, 0, 0};
// 			} else {
// 				break;
// 			}
// 		}
// 		std::sort(a.begin(), a.end(), cmpc1);
// 		for (stu j:a) {
// 			ans += std::max(j.a, j.b);
// 		}
// 	}
// 	printf("%lld\n", ans);
// 	return ;
// }

int main() {
	#ifndef DEBUG
	file(club);
	#endif

	t = read();
	while (t--) {
		work();
	}

	return 0;
}