#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

int a[110];
bool cmp(int x, int y) {return x > y;}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int l = n * m;
	for(int i = 1; i <= l; i++) cin >> a[i];
	int cur = 0, k = 0, sc = a[1];
	sort(a + 1, a + l + 1, cmp);
	for(int i = 1; i <= l; i++)
		if(a[i] == sc) k = i;
	int x = 1, y = 1;
	while(cur < k)
	{
		cur++;
		if(cur == k)
		{
			cout << y << " " << x << '\n';
			break;
		}
		if(y % 2 == 1)
		{
			x++;
			if(x > n) x = n, y++;
		}
		else
		{
			x--;
			if(x < 1) x = 1, y++;
		}
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}
