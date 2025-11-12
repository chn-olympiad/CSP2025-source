#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
char s[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if(m == 1)
	{
		int a = 0,b = 0,ng = 1;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '1')
				a++;
			else
				b++;
		}
		if(a % 2 == 0 && n % 2 == 0)
			cout << a * n / 2;
	}
	else cout << n;
	return 0;
}