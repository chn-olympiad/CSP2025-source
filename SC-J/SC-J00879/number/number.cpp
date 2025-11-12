#include<bits/stdc++.h>
using namespace std;
string s,ans;
long long a[1000010],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
		 	a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		ans+=char(a[i]+'0');
	}
	if(ans[0]=='0')
	{
		cout<<"0";
	}
	else
	{
		cout<<ans;
	}
	return 0;
}