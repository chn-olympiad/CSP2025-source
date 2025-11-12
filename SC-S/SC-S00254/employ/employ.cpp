#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 998244353;

int n, m, c[N];

long long ans = 1, jsq;

string str;

int main ()
{
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> str;
    for (int i = 1;i <= n;i ++) 
	{
		cin >> c[i];
		if (c[i] == 0)
		{
			jsq ++;
		}
	}
	if (m == n && jsq)
	{
		cout << 0;
		return 0;
	}
	if (n - jsq < m) cout << 0, exit (0);
//	cout << jsq << endl;
    for (int i = n - jsq;i >= 2;i --)
    {
    	ans *= i;
    	ans %= MOD;
	}
	cout << ans;
    return 0;
} 
//╔我看到了我的爱恋╝
//╔我飞到了她的身边╝
//╔拿出我送给她的礼物╝
//╔那是一小块凝固的时间╝
//╔上面有美丽的花纹╝
//╔她将时间涂满全身╝
//╔挽着我的手自在飞行╝
//╔这是灵态的飞行╝
//╔就像幽灵一样虚幻╝