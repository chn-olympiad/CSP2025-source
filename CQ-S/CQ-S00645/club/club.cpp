#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int t, n, ans;
int a[N], b[N], c[N], num[4], per[4];
//bool p[N];
//int num1, num2, num3;
//int getnum(int l) {
//	long long res = 0;
//	for(int i = 1; i <= n; i++) {
//		if(p[i] == 0) {
//			if(res < a[i][l]) res = a[i][l], per[l] = i;
//		}
//	}
//	return res;
//}
//int dp[N / 2][N / 2][N / 2];
//pair<int, pair<int, int> > a1[N];
//int tot;
//bool cmp(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y) {
//	return x.second.second > y.second.second;
//}
//bool cho[N];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		ans = 0;
//		memset(cho, 0, sizeof(cho));
//		memset(num, 0, sizeof(num));
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
//		for(int i = 1; i <= n; i++) {
//			if(num[1] < n / 2 && num[2] == n / 2 && num[3] == n / 2) {
//				ans += getnum(1);
//				p[per[1]] = 1;
//				num[1]++;
//			}
//			else if(num[1] == n / 2 && num[2] < n / 2 && num[3] == n / 2) {
//				ans += getnum(2);
//				p[per[2]] = 1;
//				num[2]++;
//			}
//			else if(num[1] == n / 2 && num[2] == n / 2 && num[3] < n / 2) {
//				ans += getnum(3);
//				p[per[3]] = 1;
//				num[3]++; 
//			}
//			else if(num[1] < n / 2 && num[2] < n / 2 && num[3] == n / 2) {
//				int qwe1 = getnum(1), qwe2 = getnum(2);
//				if(qwe1 <= qwe2) {
//					ans += qwe2;
//					p[per[2]] = 1;
//					num[2]++;
//				}
//				else {
//					ans += qwe1;
//					p[per[1]] = 1;
//					num[1]++;
//				}
//			}
//			else if(num[1] == n / 2 && num[2] < n / 2 && num[3] < n / 2) {
//				int qwe2 = getnum(2), qwe3 = getnum(3);
//				if(qwe2 <= qwe3) {
//					ans += qwe3;
//					p[per[3]] = 1;
//					num[3]++;
//				}
//				else {
//					ans += qwe2;
//					p[per[2]] = 1;
//					num[2]++;
//				}
//			}
//			else if(num[1] < n / 2 && num[2] == n / 2 && num[3] < n / 2) {
//				int qwe1 = getnum(1), qwe3 = getnum(3);
//				if(qwe1 <= qwe3) {
//					ans += qwe3;
//					p[per[3]] = 1;
//					num[3]++;
//				}
//				else {
//					ans += qwe1;
//					p[per[1]] = 1;
//					num[1]++;
//				}
//			}
//			else {
//				int qwe1 = getnum(1), qwe2 = getnum(2), qwe3 = getnum(3);
//				if(qwe1 < qwe2)
//			}
//		} 
//		for(int i = n; i >= 1; i--) {
//			for(int x = 1; x <= n/2; x++) {
//				for(int y = n/2; y >= 1; y--) {
//					for(int z = n - x - y; z >= 1; z--) {
//						dp[x][y][z] = max(dp[x-1][y][z]+a[i][1],max(dp[x][y-1][z]+a[i][2],dp[x][y][z-1]+a[i][3]));
//					}
//				}
//			}
//		}
//		int maxn = 0;
//		for(int x = n/2; x >= 1; x--) {
//			for(int y = n/2; y >= 1; y--) {
//				for(int z = n - x - y; z >= 1; z--) {
//					cout << dp[x][y][z] << ' ';
//				}
//				cout << endl;
//			}
//			cout <<endl;
//		}
//		cout << maxn << endl;
//		for(int i = 1; i <= n; i++) {
//			tot++;
//			a1[tot].first = i; a1[tot].second.first = 1, a1[tot].second.second = a[i][1];
//			tot++;
//			a1[tot].first = i; a1[tot].second.first = 2, a1[tot].second.second = a[i][2];
//			tot++;
//			a1[tot].first = i; a1[tot].second.first = 3, a1[tot].second.second = a[i][3];
//		}
//		sort(a1 + 1, a1 + tot + 1, cmp);
//		for(int i = 1; i <= tot; i++) {
//			if(cho[a1[i].first] == 0 && num[a1[i].second.first] < n / 2) {
//				ans += a1[i].second.second;
//				cho[a1[i].first] = 1;
//				num[a1[i].second.first]++;
//			}
//		}
//		cout << ans;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n / 2; i++) ans += a[i];
		cout << ans << endl;
	}
	
	return 0;
}

