#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for (long long i=0;i<s.length();i++)
	{
		
		
		if (s[i]>='0' && s[i]<='9')
		{
			
			a[++m]=s[i]-'0';
			
			
		}
	}
	sort(a+1,a+m+1);
	for (long long i=m;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
