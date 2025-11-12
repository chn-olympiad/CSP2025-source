#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[(int)(s[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			putchar((char)('0'+i)); 
	return 0;
}

