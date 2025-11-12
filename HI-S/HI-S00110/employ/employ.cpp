#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500;
const int LIM = 998244353;

int n, m;
string s;
int c[MAX_N];
int p[MAX_N];

int res;

void read()
{
	scanf("%d %d", &n, &m);
	
	cin >> s;
	
	for (int i = 0; i < n; i ++)
	{
		scanf("%d", &c[i]);
		p[i] = i;
	}
}

void slove()
{
	do
	{
		int fn = 0, sn = 0;
		for (int i = 0; i < n; i ++)
		{
			if (s[i] == '0' || fn >= c[p[i]])
			{
				fn ++;
				
				if (fn + m >= n)
				{
					continue;
				}
			}
			else
			{
				sn ++;
				
				if (sn >= m)
				{
					if (++ res >= LIM)
					{
						res = 0;
					}
					
					continue;
				}
			}
		}
		
		cout << endl;
	} while (next_permutation(p, p + n));
	
	cout << res;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	read();
	slove();
	return 0;
}


