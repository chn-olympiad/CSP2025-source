#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 100;

bool cmp(int a, int b)
{
	return a > b;
}

string s;
int num[maxn];
int cnt;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	for(int i = 0; i < s.length(); i ++)
	{
		if(isdigit(s[i]))
		{
			num[cnt] = s[i] - '0';
			cnt ++;
		}
	}
	
	
	sort(num, num + cnt, cmp);
	
	for(int i = 0; i < cnt; ++i) cout << num[i];



	return 0;
}
