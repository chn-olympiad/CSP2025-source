#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	long long  m[a.size() + 10];
	long long  n = 1;
	for(long long  i = 0;i < a.size();i ++)
	{
		if(a[i] <= '9' && a[i] >= '0')
		{
			m[n] = a[i] - '0';
			n ++;
		}
	}
	sort(m + 1,m + n);
	for(long long  i = n - 1;i >= 1;i --)
	{
		cout << m[i];
	}
	return 0;
}
