#include<bits/stdc++.h>
using namespace std;
int n, m;
struct student
{
	int a;
	bool is;
	bool operator<(const student s)
	{
		return a > s.a;
	}
}s[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> s[i].a;
		s[i].is = i == 1;
	}
	sort(s + 1, s + n * m + 1);
	for (int i = 1; i <= n * m; i++)
	{
		if (s[i].is)
		{
			cout << (i - 1) / n + 1 << ' ';
			if (((i - 1) / n + 1) & 1)
			{
				cout << (i - 1) % n + 1 << endl;
			}
			else
			{
				cout << n - (i - 1) % n << endl;
			}
		}
	}
	return 0;
}