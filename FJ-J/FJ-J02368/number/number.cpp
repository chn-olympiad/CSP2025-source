#include <bits/stdc++.h>
using namespace std;
int a[1000],n=1;
string s;
int main() 
{
	freopen("number.in","w",stdin);
	cin>>s;
	for (int i=0;i<=s.length();i++)
	{
		if ((s[i]>='0')&&(s[i]<='9'))
		{
			a[n] = s[i]-48;
			n++;
		}		
	}
	sort(a+1,a+n+1);
	for (int i = n;i>=2;i--)
	{
		cout<<a[i];
	}
	freopen("number.out","r",stdout);
	return 0;
}
