#include <bits/stdc++.h>
using namespace std;
string s;
int num=0,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for (int i=0;i<n;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[++num]=s[i]-'0';
		}
	}
	sort(a+1,a+1+num);
	for (int i=num;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
