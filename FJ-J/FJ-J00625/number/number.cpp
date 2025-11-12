#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[t++]=s[i]-'0';
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
