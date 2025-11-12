#include <bits/stdc++.h>
using namespace std;

int a[100005];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt = 1;
	cin >> s;
	for(int i=0; i<s.size(); i++)
	{
		if(isdigit(s[i]))
		{
			a[cnt] = s[i]-48;
			cnt++;
		}
	}
	sort(a+1, a+cnt+1, cmp);
	for(int i=1; i<cnt; i++)
	{
		cout << a[i];
	}
	return 0;
}

