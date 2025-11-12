#include<bits/stdc++.h>
using namespace std;
int n,o,p[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			o++;
			p[o]=s[i]-'0';
		}
	}
	sort(p+1,p+o+1);
	if(p[o]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=o;i>=1;i--)
		{
			printf("%d",p[i]);
		}
	}
} 
