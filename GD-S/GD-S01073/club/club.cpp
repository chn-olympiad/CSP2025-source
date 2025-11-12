#include <bits/stdc++.h>
using namespace std;

int stu1[100005];
int stu2[100005];
int stu3[100005];
int maxf(int f[]){
	int maxfa = -114514;
	int index;
	for (int i = 0;i < 3; i++){
		if (maxfa < f[i]) {
			maxfa = f[i];
			index = i;
		}
		//cout << f[i] << " "; 
	}
	return index;
}
int main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int stu;
		cin >> stu;
		for (int i = 1; i <= stu; i++){
			cin >> stu1[i] >> stu2[i] >> stu3[i];
		}
		int am = 0, bm = 0, cm = 0;
		vector<int> tem(stu + 1, 0);
		vector<vector<int>> dp(stu / 2 + 1, tem);
		for (int i = 1;i <= stu / 2; i++) {
			for (int j = 1;j <= stu; j++) {
				int listl[3] = {(am<stu/2?stu1[j]:-1), (bm<stu/2?stu2[j]:-1), (cm<stu/2?stu3[j]:-1)};
				int choose = maxf(listl);
				if (choose == 0) {
					am++;
				} else if (choose == 1) {
					bm++;
				} else {
					cm++;
				}
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]+(listl[choose]));
				//cout << am << " " << bm << " " << cm << " " << dp[i][j] << endl;
			}
		}
		cout << dp[stu / 2][stu] << endl;
	}
	return 0;
} 

