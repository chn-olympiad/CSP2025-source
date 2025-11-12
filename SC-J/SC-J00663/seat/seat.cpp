#include <bits/stdc++.h>
using namespace std;
int n, m; // n为行数，m为列数
int s[15][15]; //用于座位存储
int f[105]; //用于存储成绩
int r; //用于存储小R同学的成绩
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n*m; i++)
	{
		cin >> f[i];
		if (i == 0)
		{
			r = f[i];
		}
	}
	sort(f, f + n*m, cmp);
	int index_ = 0; //记录排到第几位同学
	for (int i = 1; i <= m; i++) //i作为列数,j作为行数
	{
		if (i % 2 == 1) //在奇数列，从上到下排
		{
			for (int j = 1; j <= n; j++)
			{
				if (f[index_] == r) //排到小R同学，输出座位号并跳出函数
				{
					cout << i << ' ' << j;
					return 0;
				}
				s[j][i] = f[index_];
				index_ ++;
			}
		}else{ //在偶数列，从下到上排
			for (int j = n; j >= 1; j--)
			{
				if (f[index_] == r) //排到小R同学，输出座位号并跳出函数
				{
					cout << i << ' ' << j;
					return 0;
				}
				s[j][i] = f[index_];
				index_ ++;
			}
		}
	}
	
	return 0;
}