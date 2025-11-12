#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second
#define V vector
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	V<int> cnt(10, 0);
	char x = getchar();
	while(~x)
	{
		if(x >= '0' && x <= '9') ++cnt[x & 15];
		x = getchar();
	}
	for(int i = 9; i >= 0; --i)
		while(~--cnt[i])
			cout << i;
	cout << '\n';
	
	return 0;
}