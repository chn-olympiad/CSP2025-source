#include<bits/stdc++.h>
using namespace std;
string s;
int t,a[1000005]{0};
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin >> s;
	t= 1;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[t] = s[i] - 48;
			t++;
		}
	}
	sort(a + 1,a + t,cmp);
	for (int i = 1;i < t;i++)
	{
		cout << a[i];
	}
	return 0;
}
