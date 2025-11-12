#include <bits/stdc++.h>
using namespace std;
struct student
{
	int grade, id;
} a[110];
bool cmp(student a, student b)
{
	return a.grade > b.grade;
}
int c, m, n, num, r;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m * n; i ++)
		cin >> a[i].grade, a[i].id = i;
	sort(a + 1, a + m * n + 1, cmp);
	for (int i = 1; i <= m * n; i ++)
		if (a[i].id == 1)
		{
			num = i;
			break;
		}
	c = (num - 1) / n + 1, r = (c % 2 ? num - (c - 1) * n : n * c - num + 1);
	cout << c << ' ' << r;
	return 0;
}
