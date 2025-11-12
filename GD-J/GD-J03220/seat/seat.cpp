#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[205];
int score;

int c = 1, r = 0;
int y_direction = 1;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	score = a[1];
	
	sort(a + 1, a + n * m + 1, cmp);
	
//	for (int i = 1; i <= n * m; i++) cout << a[i] << " ";
	for (int i = 1; i <= n * m; i++)
	{
		r = r + y_direction;
		if (r > n)
		{
			r = r - y_direction;
			y_direction = -1;
			c++;
		}
		else if (r < 1)
		{
			r = r - y_direction;
			y_direction = 1;
			c++;
		}
		if (a[i] == score)
		{
			cout << c << " " << r << endl;
			break;
		}
//		cout << a[i] << " ";
	}
	return 0;
}

