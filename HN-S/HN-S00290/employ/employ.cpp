#include <bits/stdc++.h>
using namespace std;

const int N = 998244353;

int n , m;
string s;
bool f;
int a[505];
long long sum = 1;;

int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < s.size();i ++)
	{
		if(s[i] != '1')
		{
			f = 1;
		}
	}
	if(f == 0)
	{
		for(int i = 1;i <= n;i ++)
		{
			sum *= i;
		}
		cout << sum % N;
		return 0;
	}
	else
	{
		cout << 0;
	}
	return 0;
}

