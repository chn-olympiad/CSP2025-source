#include <bits/stdc++.h> 
#define int long long
using namespace std;

//struct sta{
//	int l, b, c;
//};
struct Stu{
	int q, id;
};
//
//sta Sta(int a, int b, int c){
//	sta t;
//	t.l=a; t.b=b; t.c=c;
//	return t;
//}
//sta mSta(sta a, sta b){
//	return (a.l < b.l ? b : a);
//}
//bool cmp(Stu a, Stu b){
//	return a.q > b.q;
//}

int n, stu[100005][3]={}, res=-1;
void dfs(int a, int b, int c, int d, int r){
	if (d == n) res = max(res, r);
	for (int i = 0; i < 3; i++){
		switch (i){
			case 0:
				if (a > 0) dfs(a-1, b, c, d+1, r+stu[d][0]);
				break;
			case 1:
				if (b > 0) dfs(a, b-1, c, d+1, r+stu[d][1]);
				break;
			case 2:
				if (c > 0) dfs(a, b, c-1, d+1, r+stu[d][2]);
				break;
		}
	}
}

signed main(){
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for (int _t = 0; _t < T; _t++){
//		int n, a[205][3]={};
		cin >> n;
		res = -1;
//		for (int i = 1; i <= n; i++){
//			cin >> a[i][0] >> a[i][1] >> a[i][2];
//		}
		int a3[100005]={};
		for (int i = 0; i < n; i++){
			cin >> stu[i][0] >> stu[i][1] >> stu[i][2];
			a3[i] = stu[i][0];
		}
//		sta dp[105][205], b, c;//dp[i][j]为当组a还有i人的空间且各社团已招收前j人时的最优状态
//		Stu a2[100005]={};//a2[i].v为当组a不招收，b组与c组各招一半时为使满意度最大各成员的修正值 
//		for (int i = 1; i <= n; i++){
//			a2[i].q = a[i][1] - a[i][2];
//			a2[i].id=i;
//		}
//		sort(a2+1, a2+n+1, cmp);
//		for (int i = 0; i <= n/2; i++){
//			dp[i][0] = Sta(0, n/2, n/2);
//		}
//		for (int i = 1; i <= n; i++){
//			if (a2[i].q > 0) dp[0][i] = Sta(dp[0][i-1].l+a[i][1], dp[0][i-1].b-1, dp[0][i-1].c);
//			else if (a2[i].q < 0) dp[0][i] = Sta(dp[0][i-1].l+a[i][2], dp[0][i-1].b, dp[0][i-1].c-1);
//			else {
//				if (dp[0][i-1].b >= dp[0][i-1].c) dp[0][i] = Sta(dp[0][i-1].l+a[i][1], dp[0][i-1].b-1, dp[0][i-1].c);
//				if (dp[0][i-1].b < dp[0][i-1].c) dp[0][i] = Sta(dp[0][i-1].l+a[i][2], dp[0][i-1].b, dp[0][i-1].c-1);
//			}
//		}
//		for (int i = 1; i <= n/2; i++){
//			for (int j = 1; j <= n; j++){
//				dp[i][j] = mSta(Sta(dp[i-1][j-1].l+a[j][0], 
//									dp[i-1][j-1].b, 
//									dp[i-1][j-1].c)/*招收*/,
//								Sta(dp[i-1][j-1].l+(dp[0][j-1].l-dp[0][j].l), 
//									dp[i][j-1].b-(dp[0][j-1].b-dp[0][j].b), 
//									dp[i][j-1].c-(dp[0][j-1].c-dp[0][j].c))/*不招收*/
//								);
//			}
//		}
//		int res = -1;
//		cout << dp[i][n/2].l << endl;
		
		if (n <= 10) dfs(n/2, n/2, n/2, 0, 0);
		else{
//			for (int i = 0; i < n; i++){
//				a2[i].q = stu[i][0] - stu[i][1];
//				a2[i].id=i;
//			}
//			sort(a2+1, a2+n+1, cmp);
//			for (int i = 0; i < n/2; i++){
//				res += stu[a2[i].id][0];
//			}
//			for (int i = n/2; i < n; i++){
//				res += stu[a2[i].id][1];
//			}
			
			res=0;
			sort(a3, a3+n, greater<int>());
			for (int i = 0; i < n/2; i++){
				res += a3[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}

