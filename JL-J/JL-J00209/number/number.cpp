#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin >> s;
	long long d = s.size(),g = 0;
	for(long long i = 0 ; i <= d ; i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			a[g] = s[i];
			g++;
		}
	}
	for(long long i = 0 ; i <= g ; i++)
		for(long long j = 0 ; j <= g ; j++)
			if(a[j] <= a[j + 1])
				swap(a[j],a[j + 1]);
	if(g == d)
		for(long long i = 0 ; i < g ; i++)
			cout << a[i];
	else
		for(long long i = 0 ; i <= g ; i++)
			cout << a[i];
	return 0;
}
