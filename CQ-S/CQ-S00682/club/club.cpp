#include <bits/stdc++.h>
#define ll long long
#define L(name, start, end) for (int name = start; name <= end; ++name)
#define R(name, start, end) for (int name = start; name >= end; --name)
using namespace std;

constexpr int N = 100005;
namespace mains{
	int n;
	int f[N][4];
	struct node {
		int a[4], mx;
		bool operator < (const node & tmp) const {
			return mx > tmp.mx;
		}
	}a[N];
//	bool cmp(int x[4], int y[4]) {
//		if (x[1] != y[1]) return x[1] > y[1];
//		if (x[2] != y[2]) return x[2] > y[2];
//		return x[3] > y[3];
//	}
	int sum[4], cnt[4];
	int mt[N][4];
	int run(int test) {
		cin >> n;
		sum[1] = sum[2] = sum[3] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		memset(mt, 0, sizeof mt);
		L(i, 1, n) a[i].mx = 0;
		L(i, 1, n) L(j, 1, 3) cin >> a[i].a[j], sum[j] += a[i].a[j], a[i].mx = max(a[i].mx, a[i].a[j]);
		sort(a + 1, a + 1 + n);
		R(i, n, 1) {
			L(j, 1, 3) mt[i][j] = mt[i + 1][j];
			L(j, 1, 3) mt[i][j] = max(mt[i][j], a[i].a[j]);
		}
		
		
//		L(i, 1, n) {L(j, 1, 3) cout << a[i].a[j] << ' '; cout << a[i].mx; cout << '\n';}
//		L(i, 1, n) {L(j, 1, 3) cout << mt[i][j] << ' ';	cout << '\n';}
		
		int answer = 0;
		L(i, 1, n) {
			int mx = 0, id = 0, mx2 = 0, id2 = 0;
			L(j, 1, 3) {
				if (a[i].a[j] > mx) {
					mx2 = mx, id2 = id;
					mx = a[i].a[j], id = j;
				} else if (a[i].a[j] > mx2) {
					mx2 = a[i].a[j], id2 = j;
				}
			}
//			cout << "[get max]" << mx  << ' ' << id << ' ' << mx2 << ' ' << id2 << '\n';
			int sum3 = a[i].a[1] + a[i].a[2] + a[i].a[3];
			if (cnt[id] == n / 2) {
				cnt[id2]++;
				answer += mx2;
			} else if (cnt[id2] == n / 2) {
				cnt[id]++;
				answer += mx;
			} else {
				int s1 = sum3 - mx + (cnt[id] + 1 == n / 2 ? mt[i + 1][id] - max(mt[i + 1][id2], mt[i + 1][6 - id - id2]) : 0);
				int s2 = sum3 - mx2 + (cnt[id2] + 1 == n / 2 ? mt[i + 1][id2] - max(mt[i + 1][id], mt[i + 1][6 - id - id2]) : 0);
				int s3 = mx + mx2 + (cnt[6 - id - id2] + 1 == n / 2 ? mt[i + 1][6 - id - id2] - max(mt[i + 1][id], mt[i + 1][id2]) : 0);
//				cout << "[debug]" << s1 << ' ' << s2 << ' ' << s3 << '\n';
				if (s1 > s3 && s2 > s3 && cnt[6 - id - id2] < n / 2) {
					answer += sum3 - mx - mx2;
					cnt[6 - id - id2]++;
//					cout << "	[choose3] " << 6 - id - id2 << ", cnt[ " << 6 - id - id2 << "] =  " << cnt[6 - id - id2] << "   this= " << sum3 - mx - mx2 << "   answer=" << answer <<  "\n";
//					cout << "	" << s1 << ' ' << s2 << ' ' << s3 << '\n';
				} else {
					if (s1 <= s2) {
						answer += mx;
						cnt[id]++;
//						cout << "	[choose1] " << id <<", cnt[" << id <<"] =  " << cnt[id] << "   this= " << mx << "   answer=" << answer <<  "\n";
//						cout << "	" << s1 << ' ' << s2 << ' ' << s3 << '\n';
					} else {
						answer += mx2;
						cnt[id2]++;
//						cout << "	[choose2] " << id2 << ", cnt["<<id2<<"] =  " << cnt[id2] << "   this= " << mx2 << "   answer=" << answer <<  "\n";
//						cout << "	" << s1 << ' ' << s2 << ' ' << s3 << '\n';
					}
				}
			}
			L(j, 1, 3)sum[j] -= a[i].a[j];
//			cout << answer << '\n';
		}
		cout << answer << '\n';
		return 0;
	}
}using namespace mains;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int T = 1;
	cin >> T;
	L(i, 1, T){
		run(i);
	}
	
	return 0;
}
