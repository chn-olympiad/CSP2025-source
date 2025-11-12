#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000002],cnt=0,tot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			tot++;
		}
		if(s[i]>='1'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	for(long long i=1;i<=tot;i++)
	{
		cout<<0;
	}
	return 0;
}