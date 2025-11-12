#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
int a[1000005],p;
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && '9' >= s[i]) a[++p] = s[i] - '0';
	}
	sort(a + 1,a + p + 1,cmp);
	for (int i = 1; i <= p; i++) cout << a[i];
	return 0; 
}
