#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n, m,ans = 1,c[505],nx[505],j;
string s;
bool flag;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		if(s[i] == '0')
		{
			flag = true;
			nx[j] = i + 1;
			
			j++;
		}
	}
	j--;
	if(!flag)
		{
			for(int i = 2; i <= n; i++)
			{
				ans *= i;
				ans %= mod;
			}
			
		}
		else
		{
			sort(c + 1,c + 1 + n);
			for (int i = 0; i < n; i++)
			{
				if(c[i] < j + 1)
				{
					ans *= nx[j] - nx[j-1];
					j--;
				}
			}
		}
	cout << ans;
	return 0;
}
