#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
int a[N], idx;
bool cmp1(int a, int b)
{
	return a > b;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
	    if (s[i] >= '0' && s[i] <= '9')
	    {
	        a[idx] = s[i] - '0';
	        idx ++;
		}
	}
	sort(a, a+idx, cmp1);
	if (a[0] == 0) cout << 0;
	for (int i = 0; i < idx; i++) cout << a[i];
}