#include <bits/stdc++.h>
using namespace std;

int a[100005],n;
char s[100005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> s;
	}
	sort(s,s+1);
	cout << s;
	return 0;
}
