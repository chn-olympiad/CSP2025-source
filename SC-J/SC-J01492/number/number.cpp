#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int a[N], t = 0;
bool sg[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i<s.length(); i++ )
	{
		if( s[i]>='0' && s[i]<='9' )	a[++t] = s[i]-'0';
	}
	for(int i = 1; i<=t; i++ )
	{
		for(int j = i+1; j<=t; j++ )
		{
			if( a[j]>a[i] )	swap( a[i], a[j] );
		}
	}
	for(int i = 1; i<=t; i++ )
	{
		cout << a[i];
	}
	return 0;
} //end