#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
//int t, n;
//int a[N][4];
//int cnt[4];
//int cntid[N];
//struct eage{
//	int num, id;
//};
//void CLEAR(){
//	cnt[1] = 0;
//	cnt[2] = 0;
//	cnt[3] = 0;
//}
//void cla() {
//	CLEAR();
//	int ans = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i ++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		eage Max, Min, Mid;
//		if (x >= z && x >= y) {
//			Max.num = x;
//			Max.id = 1;
//		}else if (y >= x && y >= z) {
//			Max.num = y;
//			Max.id = 2;
//		}else{
//			Max.num = z;
//			Max.id = 3;
//		}
//		//Max
//		if (x <= z && x <= y) {
//			Min.num = x;
//			Min.id = 1;
//		}else if (y <= x && y <= z) {
//			Min.num = y;
//			Min.id = 2;
//		}else{
//			Min.num = z;
//			Min.id = 3;
//		}
//		//Min
//		if (x != Max.num  && x != Min.num) {
//			Mid.num = x;
//			Mid.id = 1;
//		}else if (y != Max.num  && y != Min.num) {
//			Mid.num = y;
//			Mid.id = 2;
//		}else{
//			Mid.num = z;
//			Mid.id = 3;
//		} 
//		// 排序
//		if (cnt[Max.id] + 1 <= n / 2) {
//			ans += Max.num;
//			cnt[Max.id] ++;
//		}else if (cnt[Mid.id] + 1 <= n / 2) {
//			ans += Mid.num ;
//			cnt[Mid.id] ++;
//		}else {
//			ans += Min.num;
//			cnt[Min.id] ++;
//		}
//		cout << "sbsb" << endl;
//		cout << Max.num << " " << Max.id << endl;
//		cout << Mid.num << " " << Mid.id << endl;
//		cout << Min.num << " " << Min.id << endl;
//		cout << "sbsb" << endl;
//	}
//	cout << ans << endl;
//}

//满分（上面） 
//5分(下面) 

int n, t;
int a[N][4];
void cl() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	int Max = -1;
	for(int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			if (i != j && a[1][i] + a[1][j] >= Max) {
				Max = a[1][i] + a[1][j];
			}
		}
	}
	cout << Max;
}
int main() {
	freopen(club.in, "r", stdin);
	freopen(club.out, "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i ++) {
		cl();
	}
	return 0;
} 
