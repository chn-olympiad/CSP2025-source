#include <bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (long long i = 0; i < (long long)(s.size()); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int t = (int)(s[i] - '0');
            a[t]++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        for (long long j = 1; j <= a[i]; j++)
        {
            cout << i;
        }
    }
    cout << '\n';
	return 0;
}
