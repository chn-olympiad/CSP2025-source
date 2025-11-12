#include<bits/stdc++.h>
using namespace std;
string s;
int x=0,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&& s[i]<='9')
		{
			a[x]=int(s[i]);
			x++;
		}
	}
	sort(a,a+x);
	for (int i=x-1;i>=0;i--)
	{
		cout<<char(a[i]);
	}
	return 0;
} 
