#include <bits/stdc++.h>
using namespace std;
int main(){
	//一定要改!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 0;//行 
	int m = 0;//列
	int r = 0;//答案——行
	int c = 0;//答案——列 
	cin >> n >> m;
	int sum = n*m;
	int grade[sum + 1] = {};
	int seat[n][m];
	for (int i = 1; i <= sum; i++){
		cin >> grade[i];
	}
	//数组未排序前保存R哥(bushi)的成绩 
	int grader = grade[1];
	//冒泡排序(我只会写这个了) 
	for (int i = 1; i <= sum; i++){
		for (int j = 1; j <= sum; j++){
			int num = grade[j];
			if (num < grade[j + 1]){
				grade[j] = grade[j + 1];
				grade[j + 1] = num;
			}
		}
	}
	//特判 
	if (grader == grade[1]){
		cout << 1 << " " << 1;
	}
	//分区间排序，若x为奇数，则按索引顺序取奇数区间内grade中的值；若x为偶数，则逆序取偶数区间内grade中的值 
	for (int x = 1; x <= m; x++){
		for (int y = 1; y <= n; y++){
			if (x % 2 == 1){
				int past = n*(x - 1);
				if (grader == grade[past + y]) {
					r = y;
					c = x;
					break;
				}
				seat[y][x] = grade[past + y];  
			}
			else{
				int now = n*x;
				if (grader == grade[now + 1 - y]) {
					r = y;
					c = x;
					break;
				}
				seat[y][x] = grade[now + 1 - y];
			}
		}
	} 
	//程序先输出列(m,c)， 再输出行(n,r) 
	cout << c << " " << r;
	return 0; 
} 
