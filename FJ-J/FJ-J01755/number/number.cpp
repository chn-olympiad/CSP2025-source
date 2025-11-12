#include <bits/stdc++.h>
using namespace std;
int pos,num[1000005];
string s;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> s;
	for(int i = 0;i <= s.size() - 1;i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			pos++;
			if(s[i] == '0')
			{
				num[pos] = 0;
			}
			if(s[i] == '1')
			{
				num[pos] = 1;
			}
			if(s[i] == '2')
			{
				num[pos] = 2;
			}
			if(s[i] == '3')
			{
				num[pos] = 3;
			}
			if(s[i] == '4')
			{
				num[pos] = 4;
			}
			if(s[i] == '5')
			{
				num[pos] = 5;
			}
			if(s[i] == '6')
			{
				num[pos] = 6;
			}
			if(s[i] == '7')
			{
				num[pos] = 7;
			}
			if(s[i] == '8')
			{
				num[pos] = 8;
			}
			if(s[i] == '9')
			{
				num[pos] = 9;
			}
		}
	}
	sort(num + 1,num + pos + 1,cmp);
	for(int i = 1;i <= pos;i++)
	{
		cout << num[i];
	}
	return 0;
}
