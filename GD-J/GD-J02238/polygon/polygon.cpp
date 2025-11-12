#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int d = max(max(a, b), c);
	if(a + b + c > 2 * d) cout << 1;
	else cout << 0;
	return 0;
}
