#include<bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int a[M];
bool cmp(int x , int y)
{
	return x > y;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int idx = 0;
	int len = s.size();
	for(int i = 0 ; i < len ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			a[++idx] = s[i] - '0';
	}
	sort(a + 1 , a + idx + 1 , cmp);
	for(int i = 1 ; i <= idx ; i++)
		cout << a[i];
	return 0;
}
