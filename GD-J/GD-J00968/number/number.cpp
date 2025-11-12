#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

string s;
int len,a[N],num;

void gc()
{
	cin >> s;
	len=s.length();
	for (int i = 0;i <= len-1;i++)
		if (s[i]>='0'&&s[i]<='9')
			a[++num]=s[i]-'0';
	sort(a+1,a+num+1);
	for (int i = num;i >= 1;i--)
		cout << a[i];
	return;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gc();
	return 0;
} 
