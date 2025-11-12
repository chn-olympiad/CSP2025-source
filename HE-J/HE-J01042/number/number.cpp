#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
int a[N], cur;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[++cur] = s[i] - '0';
	sort(a + 1, a + cur + 1);
	for(int i = cur; i >= 1; i--) cout << a[i];
	return 0;
}
