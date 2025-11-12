#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while(cin >> ch)
	{
		if(ch <= '9' && ch >= '0')
		{
			a[++cnt] = ch - '0';
		}
	}
	sort(a + 1,a + cnt + 1);
	for(int i = cnt; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
 } 
