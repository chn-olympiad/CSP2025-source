#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s,ans;
ll a[15];               
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		    a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			ans=ans+char(i+'0');
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
 } 
