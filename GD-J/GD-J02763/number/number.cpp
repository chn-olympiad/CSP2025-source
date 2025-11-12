#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size(), cur = 0;
	for(int i = 0; i < len; i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			a[++cur] = s[i] - '0';
	}
	sort(a + 1, a + cur + 1);
	for(int i = cur; i > 0; i --)
		cout << a[i];
	return 0;
} 
