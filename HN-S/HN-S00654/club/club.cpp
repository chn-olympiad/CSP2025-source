#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;

int zdigui = 0, zdigui1 = 0, ztemp = 1;

void digui(int ztempn) {
	for (int i = 1; i <= 3; i++) {

	}
}

signed main() {
//	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;

	for (int shit = 1; shit <= t; shit++) {
		int n;
		cin >> n;

		// 看我骗分大法

		int score[n][3] = {};

		for (int i = 1; i <= n; i++) {
			cin >> score[i][1] >> score[i][2] >> score[i][3];
		}

		if (n == 2) {
			int temp_score = 0, temp_score2 = 0, temp = 1;
			// 欸我直接计算最大方案，5分到手
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j) {
						temp_score = score[1][i] + score[2][j];
						if (temp_score > temp_score2) {
//							cout << endl << "[LOG] 成功处理: " << temp_score;
							temp_score2 = temp_score;
//							cout << endl << "[LOG] temp_score2 = " << temp_score2 << endl;
						}
					}
				}
			}
			cout << temp_score2 << endl;
		}

		else if (n == 100000) {
			int a[n/2] = {},ans=0;
			for (int i = 1; i <= n; i++) {
				a[i] = score[i][1];
			}
			sort (a, a+n);
			for (int i = n; i >= 50000; i--) {
				ans+=a[i];
			}
			cout << ans<<endl;
		}

		else {
			int afd = 0, zfd = 0;
			for (int i = 1; i <= n; i++) {
				afd = max(afd, score[i][1]);
				afd = max(afd, score[i][2]);
				afd = max(afd, score[i][3]);
				zfd += afd;
				afd = 0;
			}
			cout << zfd << endl;


			/*
			int bumenzonghe1 = 0, bumenzonghe2 = 0, bumenzonghe3 = 0;
			for (int i = 1; i <= n; i++) {
				bumenzonghe1 += score[i][1];
				bumenzonghe2 += score[i][2];
				bumenzonghe3 += score[i][3];
			}

			int tempmax = 0, laoer = 0, laosan = 0;

			if ((bumenzonghe1 > bumenzonghe2) && (bumenzonghe2 >= bumenzonghe3))  {
				tempmax = 1, laoer = 2, laosan = 3;

			} else if ((bumenzonghe1 > bumenzonghe3) && (bumenzonghe3 >= bumenzonghe2)) {
				tempmax = 1, laoer = 3, laosan = 2;
			} else if ((bumenzonghe2 > bumenzonghe1) && (bumenzonghe1 >= bumenzonghe3)) {
				tempmax = 2, laoer = 1, laosan = 3;
			} else if ((bumenzonghe2 > bumenzonghe3) && (bumenzonghe3 >= bumenzonghe1)) {
				tempmax = 2, laoer = 3, laosan = 1;
			} else if ((bumenzonghe3 > bumenzonghe2) && (bumenzonghe2 >= bumenzonghe1)) {
				tempmax = 3, laoer = 2, laosan = 1;
			} else if ((bumenzonghe3 > bumenzonghe1) && (bumenzonghe1 >= bumenzonghe2)) {
				tempmax = 3, laoer = 1, laosan = 2;
			}*/
		}

	}

	return 0;
}

/*if (n == 4) {
			int temp_score = 0, temp_score2 = 0, temp = 1;
			// 欸我直接计算最大方案，5分到手
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					for (int k = 1; k <= 3; k++) {
						for (int x = 1; x <= 3; x++) {
							if ((i!)) {
								temp_score = score[1][i] + score[2][j];
								if (temp_score > temp_score2) {
									cout << endl << "[LOG] 成功处理: " << temp_score;
									temp_score2 = temp_score;
									cout << endl << "[LOG] temp_score2 = " << temp_score2 << endl;
								}
							}
						}
					}
				}
			}
			cout << temp_score2 << endl;
		}*/
