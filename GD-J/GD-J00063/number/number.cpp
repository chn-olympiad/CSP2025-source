#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010],la;

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[++la] = s[i] - '0';
		}
	}
	sort(a + 1,a + la + 1,cmp);
	bool f = 1;
	for (int i = 1;i <= la;i++)
	{
		if (a[i] == 0 && f)
		{
			continue;
		}
		else
		{
			f = 0;
			printf("%d",a[i]);
		}
	}
	if (f) printf("0\n");
	return 0;
}
