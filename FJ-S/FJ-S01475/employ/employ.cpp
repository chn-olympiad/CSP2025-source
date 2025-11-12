#include<bits/stdc++.h>
using namespace std;
int n,m; 
const int N = 998244353; 
string str; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> str;
	if(m == n)
	{
		for(int i = 0;i < str.length();++ i)
		{
			if(str[i] == '0')
			{
				cout << 0;
				return 0;
			}
		}
		for(int i = 1;i <= n;++ i)
		{
			int x;
			cin >> x;
			if(x == 0)
			{
				cout << 0;
				return 0;
			}
		}
	}
	int num = n;
	for(int i = 1;i <= n;++ i)
	{
		int x;
		cin >> x;
		if(x == 0)
		{
			-- num;
		}
	}
	int ans = 1;
	for(int i = 1;i <= num;++ i)
	{
		ans *= i;
		ans %= N;
	}
	cout << ans;
	return 0;
}
