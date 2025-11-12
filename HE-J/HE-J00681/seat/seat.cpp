#include <bits/stdc++.h>
using namespace std;
int main() {
	
	freopen("seat.in","r", stdin);
	freopen("seat.out","w", stdout);
	////
	// 行数和列数
	int n, m; 
	cin >> n >> m; 
	
	// 所有人的分数
	int a[n * m + 5]; 
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	
	//我的分数
	int myA = a[1]; 
	
	// 降序
	sort(a + 1, a + m * n + 1);
	int b[n * m + 5], d = 1;
	for (int i = n * m; i >= 1; i--) {
		b[d] = a[i];
		d += 1;
	}
	
	// 我的列与行 
	int c = 1, r = 1; 
	
	//查找我的位置
	int myW = 0;
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == myA) {
			myW = i;
			break;
		}
	} 
	int myW2 = myW;
	for (int i = 1; i <= n* m; i++) {
		if (i * m >= myW) {
			myW = i * m;
			break;
		}
	}
	//cout << myW << endl;
	
	//列 
	c = myW / m;
	
	cout << c << " " << r;
	
	return 0;
}
