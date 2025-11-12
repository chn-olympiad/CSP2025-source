#include <bits/stdc++.h>

using namespace std;
string str;
int cnt[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if('0' <= str[i] && str[i] <= '9')
			cnt[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<cnt[i];j++)
			printf("%d", i);
	}
	return 0;
}

