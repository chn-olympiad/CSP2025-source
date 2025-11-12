#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt = -1;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			flag = false;
		}
	}
	if (flag)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i + 1] > s[i])
			{
				int cnt = s[i + 1];
				cnt = s[i];
				s[i] = s[i + 1];
				s[i + 1] = cnt;
				
			}
		}
		cout << s;
		return 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			continue;
		}
		else
		{
			cnt++;
			s[i] = s[i + 1];
			s[i + 1] = s[i];
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (s[i] < s[i + 1])
		{
			s[i] = s[i + 1];
			s[i + 1] = s[i];
		}
	}
	cout << s;
	return 0;
}

//我真无语了 我们下周期中考试 这周末就要考CSP
//不要搞行不行，我还要复习呢
//会不会卡时间啊！！-_-
//浪费我宝贵的复习时间
//结果到时候这个玩意不咋地 复习也没复习好
//服了 
