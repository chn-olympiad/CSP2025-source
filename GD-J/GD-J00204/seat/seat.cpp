#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return (a > b);
}

int scores[200] = {};
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, s, ord;
	cin >> n >> m;
	for (int i = 0; i < n*m; i++)
	{
		cin >> scores[i];
	}
	s = scores[0];
	sort(scores, scores + n * m, cmp);
	for (int i = 0; i < n * m; i++) //find
	{
		if (scores[i] == s)
		{
			ord = i + 1;
			break;
		}
	}
	int c = (ord % n == 0) ? ord / n : ord / n + 1, r;
	if (c % 2 == 1)
		r = (ord % n == 0) ? n : ord % n;
	else
		r = (ord % n == 0) ? 1 : (n - ord % n + 1);
	cout << c << ' ' << r;
	
	return 0;
}
