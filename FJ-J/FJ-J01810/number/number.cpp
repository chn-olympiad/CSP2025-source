#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();++i)
	{
		if ('0'>s[i] ||'9'<s[i])
		{
			continue;
		}
		a[(int)(s[i])-'0']++;
	}
	for(int i=9;i>=0;--i)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
	
}
