#include <iostream>
#include <algorithm>
using namespace std;

int students[105];

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R, score, c, r;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> students[i];
	R = students[1];
	sort(students + 1, students + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
//		cout << students[i] << endl;
		if (students[i] == R)
		{
			score = i; 
			break;
		}
	}
//	cout << score << endl;
	c = score / n + (score % n != 0);
	if (c % 2 == 0)
		r = n - (score % n == 0 ? n - 1 : score % n - 1);
	else
		r = (score % n == 0 ? n : score % n);
	cout << c << " " << r << endl;
	return 0;
}
