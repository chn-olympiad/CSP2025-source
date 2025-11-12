#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int times[20];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			times[s[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		while(times[i] > 0)
		{
			printf("%d", i);
			times[i]--;
		}
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
