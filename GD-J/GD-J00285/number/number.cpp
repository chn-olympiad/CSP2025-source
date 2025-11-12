#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],i1,b[15],b1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++) if(s[i] >= '0' && s[i] <= '9') b[(int)(s[i] - '0')]++;
	for(int i = 10;i > 0;i--)
	{
		while(b[i])
		{
			b1 = 1;
			b[i]--;
			cout << i;
		}
	}
	if(b[0])
	{
		if(b1) for(int i = 0;i < b[0];i++) cout << 0;
		else cout << 0;
	}
	return 0;
}
