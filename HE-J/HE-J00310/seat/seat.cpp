#include <iostream>
#include <cmath>

int s, temp;
int a = 1, n, m;
int row, col, r;

void GetSeat(int a);

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	std::cin >> n >> m;
	
	std::cin >> s;
	for (long long i = 0; i < n * m - 1; i++)
	{
		std::cin >> temp;
		if (temp > s)
			a++;
	}
	
	GetSeat(a);
	
	std::cout << col << ' ' << row << std::endl;
	return 0;
}

void GetSeat(int a)
{
	col = std::ceil(1.0 * a / n);
	r = a - (col - 1) * n;
	if (col % 2 == 0)
		row = n - r + 1;
	else
		row = r;
}
