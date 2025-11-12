#include <bits/stdc++.h>
using namespace std;
long a[1000010],l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long i=0;i<(long)s.length();i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--)
	{
		cout<<a[i];
	}

	return 0;
}