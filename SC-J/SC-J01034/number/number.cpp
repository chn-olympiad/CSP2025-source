#include <bits/stdc++.h>
#define V vector
using namespace std;

string s;
V<int> vec;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i : s)
		if(i >= '0' && i <= '9')
			vec.push_back(i & 15);
	sort(vec.begin(), vec.end(), [](int o, int p) {
		return o > p;
	});
	for(int i : vec)
		cout << i;
	return 0;
} 