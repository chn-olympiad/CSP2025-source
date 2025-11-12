#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n, m; // 考场的座位的行和列
	int c, r; // 小R的座位号
	int Rscore = 0;
	
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	
	cin >> n >> m;
	cin >> Rscore;
	
	vector<int> ss(0);
	
	// 输入 
	for (int i=0;i<n*m - 1; i++){
		int a;
		cin >> a;
		ss.push_back(a);
	}
	
	// 排序 
	sort(ss.begin(), ss.end());
	
//	for (int i=0;i<ss.size();i++){
//		cout << ss[i] << ' ';
//	} 
//	cout << endl;
	
	for (int i=1;i<=n;i++){ // 列 
		if (i % 2 == 0){
			for (int j = m; j>=1;j--){ // 行 
				int ThisGayScore = ss.back();
				ss.pop_back();
//				cout << "This2: "<< ThisGayScore << endl;
				if (Rscore > ThisGayScore) {
					cout << j << " " << i << endl;
					return 0;
				}
			}
		} else {
			for (int j=1;j<=m;j++){
				int ThisGayScore = ss.back();
				ss.pop_back();
//				cout << "This1: "<< ThisGayScore << endl;
				if (Rscore > ThisGayScore) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		
	} 
	
	cout << "Man" << endl;
	return 0; // What can i say 
}
