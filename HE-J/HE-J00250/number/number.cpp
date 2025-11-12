#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[1000005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s,p = "";
	cin >> s;
	long long ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int x = int(s[i]) - 48;
		if(x >= 0 && x <= 9)
		{
			ans++;
			a[ans] = x;	
		}
	}
	sort(a+1, a+ans+1, cmp);
	for(int i = 1; i <= ans; i++)
	{
		p += char(a[i] + 48);
	}
	cout << p << endl;
	return 0;
} 

