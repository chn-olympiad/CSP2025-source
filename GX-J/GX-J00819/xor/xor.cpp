#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int s[4];
	for(int i=0;i<4;i++)
		cin >> s[i];
	sort(s, s+4);
	cout << s[2];
	return 0;
}
