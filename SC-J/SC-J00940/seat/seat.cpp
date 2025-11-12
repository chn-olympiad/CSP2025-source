#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	
	int n, m; //	共有 n * m 名考生
	cin >> n >> m; // 输入的第一行包含两个正整数 n, m	表示 R 所在考场座位的行列.数
	vector<int> A(n * m + 1); // 表示考场所有考生第一轮成绩
	_loopc(i, 1, n * m)
		cin >> A[i]; // 输入的第二行包含 n × m 个正整数 a1, a2, . . . , an×m (第一轮成绩互不同)
	
	int val = A[1]; // 其中 a1 为 R 第一轮的成绩
	sort(A.begin() + 1, A.end(), greater<int>()); // 由高到低
	
	// 蛇形分配座位
	int c = 1, r = 1; // c 列 r 行
	_loopc(i, 1, n * m){ //	排列成 n 行 m 列
		if(A[i] == val) // 匹配 R 第一轮的成绩
			break; // 匹配成功
		
		if(c % 2 == 0){ // 单调下降
			r --; // r 下降
			if(r == 0) // 该下一列
				r = 1, c ++; // 下一列初始化
		}
		else{ // 单调上升
			r ++; // r 上升
			if(r == n + 1) // 该下一列
				r = n, c ++; // 下一列初始化
		}
	}
	
	printf("%d %d", c, r); //  求出 R 座位为第几列第几行 	
	return 0;
}