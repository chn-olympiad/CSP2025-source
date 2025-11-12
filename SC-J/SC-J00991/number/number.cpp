#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> s;
	int len = s.length();
	int num_n = 0;
	for (int i = 0;i < len;i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[++num_n] = s[i] - '0';
		}
	} 
	sort(a + 1,a + 1 + num_n,cmp);
	for (int i = 1;i <= num_n;i++)
		cout << a[i];
	return 0;
}