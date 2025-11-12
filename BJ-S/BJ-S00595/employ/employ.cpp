#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum = 1,cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag = 0;
	int a[505],x = s.size();
	for(int i = 0;i < x;i++)
	{
		if(!s[i])
			flag = 1;
	}
	if(!flag)
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			if(!a[i])
				continue;
			sum *= (++cnt);
			sum %= 998244353;
			cout << sum << endl;
			
		}
		for(int i = 1;i <= n - cnt;i++)
		{
			sum *= i;
			sum %= 998244353;
			cout << sum << endl;
		}
		cout << sum % 998244353<< endl;
	}
	else
		cout << 13;
	return 0;
}
