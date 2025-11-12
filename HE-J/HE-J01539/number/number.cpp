#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[s.size()];
	long long i,w=0,j,WW=0,W1W=0;
	for(i=0;i<s.size();i++)
	{
		a[i]='a';
	}
	for(i=0;i<=s.size();i++)
	{
		char smax='a';
		long long wei=0;
		for(j=0;j<s.size();j++)
		{
			if(smax=='a')
			{
				if(s[j]>smax-3254&&s[j]>='0'&&s[j]<='9')
				{
					smax=s[j];
					wei=j;
				}
			}
			else
			{
				for(j=0;j<s.size();j++)
				{
					if(s[j]>smax&&s[j]>='0'&&s[j]<='9')
					{
						smax=s[j];
						wei=j;
					}
				}
			}
			
		}
		if(smax!='a')
		{
			s[wei]='a';
			a[w]=smax;
			w++;
		}
	}
	for(i=0;i<w;i++)
	{
		if(a[i]!='a')
		{
			cout<<a[i];
		}
	}
	return 0;
}
