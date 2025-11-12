#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n,m;//n行，m列，n * m个考生
struct STU{
	int id_,coin_people;
}a[N];
bool cmp(STU a,STU b)
{
	return a.coin_people > b.coin_people;
}

/*
BF：共有n行，m列座位，从成绩高到低蛇形就做
求出a[1]在座位表中的位置 
*/

int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m; 
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i].coin_people;
		a[i].id_ = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	int seat_cnt = 0;
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i].id_ == 1)
		{
			seat_cnt = i;
		}
	}
	int lie_cnt = seat_cnt / n; //为座位数 / n 
	if(seat_cnt % n != 0) lie_cnt ++; //若有余数 
	//现在a[1]在第lie_cnt列里面，需要判断是从下往上还是从上往下
	//奇数行为下，偶数行为上
	if(lie_cnt % 2 == 1)//如果为奇数
	{
		//奇数行为下
		int hang_cnt = seat_cnt % n;
		if(hang_cnt == 0)//为末尾的数
		{
			cout << lie_cnt << " " << n << endl;
			return 0;
		}
		else//为从上往下的第模数个 
		{
			cout << lie_cnt << " " << hang_cnt << endl;
			return 0;	
		} 
	}
	else//为偶数 
	{
		//偶数行为上 
		int hang_cnt = seat_cnt % n;
		if(hang_cnt == 0)//为第一个的数
		{
			cout << lie_cnt << " " << 1 << endl;
			return 0;
		}
		else//为从下往上的第模数个 
		{
			cout << lie_cnt << " " << n - hang_cnt + 1 << endl;
			return 0;	
		} 
	} 
	return 0;
}