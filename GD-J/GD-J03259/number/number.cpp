#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	string s,l;
	char d;
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(s[j]<s[i])
			{
				d=s[j];
				s[j]=s[i];
				s[i]=d;
			}
		}
 }
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>=1)
		{
				cout<<s[i];
		}
	}
	return 0;
}
