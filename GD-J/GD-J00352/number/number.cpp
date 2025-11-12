#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


char t[1000005];
int n;

bool cmp(int x, int y)
{
	return x > y;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> (t + 1);
	n = strlen(t + 1);
	sort(t + 1, t + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (isdigit(t[i]))
			cout << t[i];
	}
	
	return 0;
}
