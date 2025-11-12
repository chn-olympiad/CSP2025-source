#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;//输入n,m 
	int a = n * m;//计算总人数 
	int s[a+1];//定义成绩表 
	for (int i = 1; i <= a; i++) cin >> s[i];// 输入成绩 
	int r = s[1];//提取R的成绩 
	while(1){
		bool p = 1;
		for (int i = 1; i <= a; i++){
			if (s[i] <s[i+1]){
				int m =s[i];
				s[i] = s[i+1];
				s[i+1]=m;
				p=0;
			}
		}
		if (p) break;
	} 
	int ans[n+1][m+1];//定义座位表 
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1){//奇数列 (正向排)
			for (int j= 1; j <= m; j++) ans[i][j] = s[(i-1) * m + j];
		}
		if (i % 2 == 0){//偶数列（逆向排） 
			for (int j = m; j >= 1; j--){
				int k=1;
				ans[i][j] = s[(i-1) * m + k];
				k++;
			}
		}
	} 
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		if (r == ans[i][j]) {
			cout << i << " " <<j << endl;
			break;
		}	
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
