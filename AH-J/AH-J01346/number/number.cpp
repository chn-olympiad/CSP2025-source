#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
char c[1000100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size()-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[++m]=s[i];
		}
	}
	sort(c+1,c+m+1);
	if(c[m]=='0')
	{
		cout<<0;
	}
	else
	{
		for(int i=m;i>=1;i--)
		{
			cout<<c[i];
		}
	}
	return 0;
}
