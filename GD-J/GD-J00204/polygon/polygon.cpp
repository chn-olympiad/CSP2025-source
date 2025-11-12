#include <iostream>
#include <algorithm>
using namespace std;

struct stick
{
	int l; //当前/自己 即是最大（因为升序排列） 
	int summ; //到当前木棒为止
};

stick st[5001] = {};
int n, cnt = 0;

bool canMake(int ind, int summ) //ind为末项
{
	return (summ > st[ind].l * 2);
}

void choose(int size, int last, int bro)
{
	int tail = (size > 0) ? last : -1;
	bool flag = size >= 3 && canMake(tail, st[tail].summ - bro);
	if (flag)
		cnt++;
	for (int i = tail + 1; i < n; i++)
	{
		choose(size + 1, i, bro);
		bro += st[i].l;
	}
}

bool cmp(stick a, stick b)
{
	return (a.l < b.l);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> st[i].l;
	sort(st, st + n, cmp); //按长度升序排序
	st[0].summ = st[0].l;
	for (int i = 1; i < n; i++)
		st[i].summ = st[i].l + st[i - 1].summ;
	choose(0, -1, 0);
	cout << cnt;
	
	return 0;
}
