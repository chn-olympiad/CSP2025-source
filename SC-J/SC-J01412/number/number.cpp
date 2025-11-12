#include <bits/stdc++.h>
using namespace std;

string s;
char c[1000005];

bool cmp(char a,char b)
{
	return a >= b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size(),cnt = 0;
	for(int i = 0;i < n;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt++;
			c[cnt] = s[i];
		}
	}
	
	sort(c+1,c+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		cout << c[i];
	}
	return 0;
}