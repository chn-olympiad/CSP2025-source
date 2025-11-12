#include <iostream>
#include <algorithm>
using namespace std;

int c, r;
int a, arr[105];
int rk, rs;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	
	cin >> c >> r;
	for (int i = 1; i <= c * r; i++)
		cin >> arr[i];
	a = arr[1];
	sort(arr + 1, arr + c * r + 1, cmp);
	for (int i = 1; i <= c * r; i++)
		if (arr[i] == a)
			rk = i;
	cout << (rk + r - 1) / r << ' ';
	rs = (rk - 1) % r + 1;
	if (rk & 1)
		cout << rs;
	else
		cout << c + 1 - rs; 
	
	return 0;
}
