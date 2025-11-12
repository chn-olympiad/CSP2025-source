#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	vector<int> s;
	int n, m, r;
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
	{
		int x;
		cin >> x;
		if(i == 0)
			r = x;
		s.push_back(x);
	}
	sort(s.begin(), s.end(), greater<int>());
	for(int i = 0; i < n * m; i++)
		if(s[i] == r)
			r = i + 1;
	cout << int(ceil(r * 1.0 / n)) << " " << (int(ceil(r * 1.0 / n)) % 2 == 1 ? (r % n == 0 ? n : r % n) : (r % n == 0 ? 1 : n + 1 - r % n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}