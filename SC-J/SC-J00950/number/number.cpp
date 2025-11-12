#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1919810];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;--i)
	{
		cout<<a[i];
	}
	return 0;
 } 
 //玄学FUCK CCF 