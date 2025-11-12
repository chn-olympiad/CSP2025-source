//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//typedef pair <int, int> PII;
//#define anf a[i].num[j].first
//#define anss a[i].num[j].second
//int n;
//int cnt[5];
//long long ans = 0;
//struct node {
//	PII num[5];
//	friend bool operator <(node x, node y) {
//		return x.num[1] > y.num[1];
//	}
//} a[N];
//bool cmp(PII a, PII b){
//	return a.first > b.first;
//}
//int main() {
//	freopen("club5.in", "r", stdin);
//	int T; cin >> T;
//	while (T--) {
//		cin >> n;
//		for (int i=1; i<=n; i++) {
//			cin >> a[i].num[1].first >> a[i].num[2].first >> a[i].num[3].first;
//			a[i].num[1].second = 1;
//			a[i].num[2].second = 2;
//			a[i].num[3].second = 3;
//			sort(a[i].num + 1, a[i].num + 4, cmp);		
//		}
//		sort(a + 1, a + 1 + n);
////		for (int i=1; i<=n; i++) {
////			cout << a[i].num[1].first << "<-" << a[i].num[1].second << "; ";
////			cout << a[i].num[2].first << "<-" << a[i].num[2].second << "; ";
////			cout << a[i].num[3].first << "<-" << a[i].num[3].second << "; ";
////			cout << '\n';
////		}
//		ans = 0;
//		memset(cnt, 0, sizeof cnt);
//		int top = n / 2;
//		for (int i=1; i<=n; i++) {
//			for (int j=1; j<=3; j++) {
//				if (cnt[anss] < top) {
//					cnt[anss]++, ans += anf; 
//					break;
//				}
//			}
//		}
//		cout << ans << '\n';
//	}
//	return 0;
//} 
///*
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node {
	int num[5];
} a[N];
struct nod {
	int num;
	int cnt[5];
	friend bool operator <(nod a, nod b) {
		return a.num > b.num;
	}
} dp[N][3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; i++)
			cin >> a[i].num[1] >> a[i].num[2] >> a[i].num[3];
		int top = n / 2;
		memset(dp, 0, sizeof dp);
		for (int i=1; i<=n; i++) {
			sort(dp[i - 1] + 1, dp[i - 1] + 4);
			for (int j=1; j<=3; j++) {
				int x = 1;
				while (dp[i - 1][x].cnt[j] >= top) x++;
				dp[i][j].num = dp[i - 1][x].num + a[i].num[j];
				memcpy(dp[i][j].cnt, dp[i - 1][x].cnt, sizeof dp[i - 1][x].cnt);
				dp[i][j].cnt[j]++;
			}
		}
		cout << max(dp[n][1].num, max(dp[n][2].num, dp[n][3].num)) << '\n';		
	//	for (int i=1; i<=3; i++) {
	//		for (int j=1; j<=n; j++) {
	//			cout << dp[j][i].num;
	//			cout << '(';
	//			for (int k=0; k<5; k++)
	//				cout << dp[j][i].cnt[k] << ',';
	//			cout << ')';
	//		}
	//		cout << '\n';
	//	}
	}	
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
*/
// ÕâÌâÊ«ÈË£¿£¿£¿ 
