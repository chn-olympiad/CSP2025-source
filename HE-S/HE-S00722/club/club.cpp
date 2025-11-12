#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int T, n, maxn, cnt1, cnt2, cnt3;
long long ans, ans1, ans2, ans3;
bool SpeA, SpeB, SpeA13, SpeA12;
//int a[100005][4];
struct student {
	int x, y, z;
	long long sum;
	//bool done;
} a[100005];
bool cmp(student e, student f) {
//	if (e.sum == f.sum) {
//		return e.x + e.y > f.x + f.y;
//	}
	return e.sum < f.sum;//总分小优先 
}
bool cmpA1(student e, student f) {
	if (e.x == f.x) {
		return e.y < f.y;
	}
	return e.x > f.x;
}
bool cmpA2(student e, student f) {
	if (e.y == f.y) {
		return e.x < f.x;
	}
	return e.y > f.y;
}
bool cmpA3(student e, student f) {
	return e.z > f.z;
}
inline int max3(int i, int j, int k) {
	return max(max(i, j), k);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n;
		maxn = n >> 1;
		ans1 = ans2 = ans3 = ans = 0;
		cnt1 = cnt2 = cnt3 = 0;
//		memset(a, 0, sizeof(a));
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= 3; j++) {
//				cin >> a[i][j];
//			}
//		}
		SpeA = true, SpeB = true, SpeA13 = true, SpeA12 = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x != 0) {
				SpeA12 = false;
				SpeA13 = false;
			}
			if (a[i].y != 0) {
				SpeA = false;
				SpeA12 = false;
			}
			if (a[i].z != 0) {
				SpeB = false;
				SpeA13 = false;
			}
			a[i].sum = a[i].x + a[i].y + a[i].z;
		} 
		if (SpeA12) {
			sort(a + 1, a + n + 1, cmpA3);
			for (int i = 1; i <= maxn; i++) {
				ans += a[i].z;
			}
			cout << ans << endl;
			continue ;
		}
//		if (SpeB) {
			if (SpeA) {
				sort(a + 1, a + n + 1, cmpA1);	
				for (int i = 1; i <= maxn; i++) {
					ans += a[i].x;
				}
				cout << ans << endl;
				continue ;
			}
			if (SpeA13) {
				sort(a + 1, a + n + 1, cmpA2);
				for (int i = 1; i <= maxn; i++) {
					ans += a[i].y;
				}
				cout << ans << endl;
				continue ;
			}
//			sort(a + 1, a + n + 1, cmp);
//			for (int i = 1; i <= n; i++) {
//				if ((a[i].x == max(a[i].x, a[i].y) )and (cnt1 < maxn)) {
//					cnt1 ++;
//					ans1 += a[i].x;
//				} else if (cnt2 < maxn) {
//					cnt2 ++;
//					ans2 += a[i].y;
//				}
//			}
//			long long tmp2 = 0;
//			sort(a + 1, a + n + 1, cmpA1);
//			for (int i = 1; i <= maxn; i++) {
//				ans1 += a[i].x;
//			}
//			for (int i = n; i >= maxn; i--) {
//				tmp2 += a[i].y;
//			}
//			sort(a + 1, a + n + 1, cmpA2);
//			for (int i = 1; i <= maxn; i++) {
//				ans2 += a[i].y;
//			}
//			if (ans1 == max(ans1, ans2)) {
//				ans = ans1 + tmp2;
//			} else if (ans2 == max(ans1, ans2)) {
//				tmp2 = 0;
//				for (int i = n ; i >= maxn; i--) {
//					tmp2 += a[i].x;
//				}
//				ans = ans2 + tmp2;
//			}
//			ans = ans1 + ans2;
//			cout << ans << endl;
//			continue ;
//		}
		
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (cnt1 == maxn) {
				if ((max(a[i].y, a[i].z) == a[i].y) and cnt2 < maxn) {
					ans2 += a[i].y;
					cnt2 ++;
				}
				if ((max(a[i].y, a[i].z) == a[i].z) and cnt3 < maxn) {
					ans3 += a[i].z;
					cnt3 ++;
				}
			} if (cnt2 == maxn) {
				if ((max(a[i].x, a[i].z) == a[i].x) and cnt1 < maxn) {
					ans1 += a[i].x;
					cnt1 ++;
				}
				if ((max(a[i].x, a[i].z) == a[i].z) and cnt3 < maxn) {
					ans3 += a[i].z;
					cnt3 ++;
				}
			} if (cnt3 == maxn) {
				if ((max(a[i].x, a[i].y) == a[i].x) and cnt1 < maxn) {
					ans1 += a[i].x;
					cnt1 ++;
				}
				if ((max(a[i].x, a[i].y) == a[i].y) and cnt2 < maxn) {
					ans2 += a[i].y;
					cnt2 ++;
				}
			}
			if ((max3(a[i].x, a[i].y, a[i].z) == a[i].x) and cnt1 < maxn) {
				ans1 += a[i].x;
				cnt1 ++;
			}
			if ((max3(a[i].x, a[i].y, a[i].z) == a[i].y) and cnt2 < maxn) {
				ans2 += a[i].y;
				cnt2 ++;
			}
			if ((max3(a[i].x, a[i].y, a[i].z) == a[i].z) and cnt3 < maxn) {
				ans3 += a[i].z;
				cnt3 ++;
			}
		}
		ans = ans1 + ans2 + ans3;
		cout << ans << endl;
	}
	return 0;
} 
/*
3

4     sum room
4 2 1  7  1
3 2 4  9  3
5 3 4  12 1
3 5 1  9  2

4
0 1 0  1  1
0 1 0  1  1
0 2 0  2  2
0 2 0  2  2
//this case不能总分小优先 
2
10 9 8 27 2
4 0 0  4  1


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
*/
