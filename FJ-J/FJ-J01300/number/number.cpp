#include <bits/stdc++.h>
using namespace std;
 
 
string s;
long long n[1000005] = {},cnt = 0,ans = 0;


int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i]-48 >= 0 && s[i]-48 <= 9)
		{
			n[++cnt] = s[i]-48;
		}
	}
	sort(n+1,n+cnt+1);
	for(int i = cnt;i >= 1;i--)
	{
		cout << n[i];
	}
	
	return 0;
}
