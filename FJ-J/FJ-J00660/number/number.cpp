#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000000],sum,uses = 9,times[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			times[int(s[i]-'0')]++;
			sum++;
		}
	}
	for(int i = 0;i < sum;i++)
	{
		while(times[uses] == 0)
		{
			uses--;
		}
		num[i] = uses;
		times[uses]--;
	}
	for(int i = 0;i < sum;i++)
	{
		cout << num[i];
	}
	return 0;
} 
