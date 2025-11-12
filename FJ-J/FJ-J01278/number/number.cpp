#include<bits/stdc++.h>
using namespace std;
string s, s1;
int a[1000010], l = 1;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9') a[l] = int(s[i]) - 48, l++;
	}
	sort(a + 1, a + l);
	for(int i = l - 1; i >= 1; i--) s1 += char(a[i] + 48);
	cout << s1;
	return 0;
}

