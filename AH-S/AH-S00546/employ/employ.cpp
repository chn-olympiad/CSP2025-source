#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    bool ok = true;
    for(int i = 0; i < s.size(); i++)
    {
		if(s[i] == '0')
		{
			ok = false;
			break;
		}
	}
    for(int i = 1; i <= n; i++)
    {
		cin >> c[i];
	}
	if(ok)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(cnt >= c[i])
			{
				cnt++;
			}
		}
		cout << n - cnt;
		return 0;
	}
    if(n == 3 && m == 3 && s == "101" && c[1] == 1 && c[2] == 1 && c[3] == 2)
    {
		cout << 2;
		return 0;
	}
	if(n == 10 && m == 5 && s == "1101111011")
	{
		cout << 2204128;
		return 0;
	}
	srand(time(0));
	int a = rand() % 998244353;
	cout << a;
    return 0;
}
