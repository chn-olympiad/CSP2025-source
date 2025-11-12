#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
string s;
int a[N];
int n;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0;i < (int)s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			n++;
			a[n] = s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i++)
	{
		cout << a[i];
	}
	return 0;
}
