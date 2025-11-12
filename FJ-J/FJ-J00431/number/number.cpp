#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			a[++x]=s[i]-'0';
		}
		else if(s[i]=='0')
		{
			a[++x]=0;
		}
	}
	sort(a+1,a+1+x);
	for(int i=x;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

