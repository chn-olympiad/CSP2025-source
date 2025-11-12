#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
string s;
int len,t = 1;
int a[1000001];
bool cmp ( int x,int y )
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for ( int i = 0;i <= len - 1;i++ )
	{
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			a[t] = s[i] - '0';
			t++;
		}
	}
	sort ( a + 1,a + t + 1,cmp );
	if ( a[1] == 0 )
	{
		cout << 0;
		return 0;
	}
	for ( int i = 1;i <= t - 1;i++ )
	{
		cout << a[i];
	}
	return 0;
}
