#include<bits/stdc++.h>
using namespace std;
int n , m;
string s;
int a[510] = {};
int flag[510] = {};
long long cnt = 0;
int p[510] = {};
void dfs(int step)
{
	if(step == n+1)
	{
//		for(int i = 1;i <= n;++i)
//		{
//			cout << p[i] << ' ';
//		}
//		cout << endl;
		int nos = 0;
		int sum = 0;
		for(int i = 1;i <= n;++i)
		{
			if(s[i-1] == '0')
			{
				nos++;
			}
			else
			{
				if(nos >= a[p[i]])
				{
					nos++;
				}
				else
				{
					sum++;
//					cout << i << ' ';
				}
			}
		}
		if(sum >= m)
		{
			cnt++;
		}
//		cout << endl << sum << " " << nos <<endl;
	}
	for(int i = 1;i <= n;++i)
	{
		if(flag[i] == 1)
		{
			continue;
		}
		flag[i] = 1;
		int temp = p[step];
		p[step] = i;
		dfs(step+1);
		flag[i] = 0;
		p[step] = temp;
	}
}
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	int l = 1;
	for(int i = 0;i < s.size();++i)
	{
		if(s[i] == '0')
		{
			l = 0;
			break;
		}
	}
	if(l == 1)
	{
		cnt = 1;
		for(long long i = 1;i <= n;++i)
		{
			cnt *= i;
			cnt %= 998244353;
		}
		cout << cnt <<endl;
		return 0;
	}
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << cnt << endl;
	
	return 0;
}
