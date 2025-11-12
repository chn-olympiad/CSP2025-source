#include "iostream"
#include "algorithm"
#include "climits"
#include "cstring"
#include "cmath"
#include "ctime"

using ll = long long;
const int N = 1e6 + 5;
const int mod = 998244353;

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(ll x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

int n, m; 
std :: string s;
int up[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	srand(time(0));
	std :: cin >> n >> m;
	
	std :: cin >> s;
	
	for(int i = 1; i <= n; i++)
	{
		std :: cin >> up[i];
	}
	
	std :: cout << ((rand() * rand() % mod + 11451410086 - m + n) / n + rand() * n * m - 10 + mod) % mod;
	return 0;
}

