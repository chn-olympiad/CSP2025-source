#include <bits/stdc++.h>
using namespace std;


char a[1000005];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in ","r",stdin);
	freopen("number.out ","w",stdout);
	int cur = 0;
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		if ('0' <= s[i] && s[i] <= '9') a[++cur]=s[i];
	}
	sort(a+1,a+cur+1,cmp);
	for (int i=1;i<=cur;i++) cout << a[i];
	return 0;
} 
