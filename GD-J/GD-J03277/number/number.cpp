#include<bits/stdc++.h>
using namespace std;
int a[1000010],u;
string s;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 1;i <= s.size();i++)
	{
		if(s[i - 1] >= '0' && s[i - 1] <= '9')
		{
			u++;
			a[u] = int(s[i - 1] - '0');
		}
	}
	sort(a + 1,a + s.size() + 1,cmp);
	if(a[1] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= u;i++)
	{
		cout << a[i];
	}
	return 0;
}
