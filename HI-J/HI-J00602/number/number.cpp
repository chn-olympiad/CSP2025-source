#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
long long len , i , k;
long long a[N];
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	len = s.size();
	for(i = 0 ; i < len ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[++k] = s[i] - '0';
		}
	}
	sort(a + 1 , a + k + 1);
	reverse(a + 1 , a + k + 1);
	if(a[1] == 0)
	{
		cout << 0;
	}
	else
	{
		for(i = 1 ; i <= k ; i++)
	    {
			cout << a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
