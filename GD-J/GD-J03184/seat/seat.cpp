//I love CCf forever!
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 105;
int RS , RN;//小R分数、小R名次
int RH , RL;//小R的座位行、列 
int a[N];
bool cmp(int x , int y) {
	return x > y;
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);

	int n , m;
	cin >> n >> m;//n行m列 
	for (int i = 1 ; i <= n * m ; i++) cin >> a[i];	//输入 
	RS = a[1];//标记小R分数 
	
	sort(a + 1 , a + n * m + 1 , cmp);//对分数进行排序 
	
	for (int i = 1 ; i <= n * m ; i++) 
		if (a[i] == RS)
			RN = i; //找到小R的名次 
	
	RL = (RN + n - 1) / n;//找到小R座位行数，公式：R的列 = （名次 + 列数 - 1） / 总列数 
	
	int QZ = (RL - 1) * n;//计算前面行的总人数 
	
	if (RL % 2)//在奇数列 
		RH = RN - QZ;
	else//偶数列 
		RH = m - (RN - 1 - QZ);//括号：多出来的人数（不包括自己） 
	
	//cout << RS << ' ' << RN << ' ' << QZ << endl;
	cout << RL << ' ' << RH;//先输出列，再输出行 
	
	return 0;
}
//I love CCf forever!

