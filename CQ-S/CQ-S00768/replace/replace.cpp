#include "iostream"
#include "algorithm"
#include "climits"
#include "cstring"
#include "cmath"
#include "map"

using ll = long long;
const int N = 1e6 + 5;

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

int n, q;

std :: string s1[N], s2[N];
std :: string a, b;
std :: map<std :: string, std :: string>s;

inline void solve()
{
	std :: cin >> a >> b;
	int ans = 0;
	std :: string ta = "", tb = "";
	for(int i = 0; i < a.size(); i++)
	{
		for(int len = 1; len < a.size(); len++)
		{
			for(int j = i; j < i + len - 1 && j < a.size(); j++)
			{
				ta += a[j], tb += b[j];
				if(s[ta] == tb) 
				{
					int f = 1;
					for(int k = 0; k < i - 1; k++)
					{
						if(a[k] != b[k]) 
						{
							f = -1;
							break;
						}
					}
					for(int k = j + 1; k < a.size(); k++)
					{
						if(a[k] != b[k]) 
						{
							f = -1;
							break;
						}
					}
					std :: cout << i << ' ' << j << ' ' << ta << ' ' << tb << '\n';
					if(f == 1) ans++;
				}
			}
			ta = "", tb = "";
		}
	}
	std :: cout << ans << '\n';
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	std :: cin >> n >> q;
	
	for(int i = 1; i <= n; i++)
	{
		std :: cin >> s1[i] >> s2[i];	
		s[s1[i]] = s2[i];
		s[s2[i]] = s[s1[i]];
	} 
	
	while(q--)
	{
		solve();
	}
	return 0;
}

