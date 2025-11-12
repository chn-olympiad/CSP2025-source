#include<bits/stdc++.h>
using namespace std;
int num[1000010];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0;i<s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt++;
			num[cnt] = (s[i] - '0');
		}
	}
	sort(num+1,num+cnt+1);
	bool flag = 0;
	for (int i = cnt;i>=1;i--)
	{
		if(flag == 0 && num[i] == 0)
		{
			continue;
		}
		else
		{
			flag = 1;
			cout << num[i];
		}
	}
	return 0;
}

