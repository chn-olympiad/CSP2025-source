#include<bits/stdc++.h>
using namespace std;
int d=0;
char b[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[d]=s[i];
			d++;
		}
	}
	char ma;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<s.size();j++)
		{
			if(b[i]>b[j])
			{
				ma=b[i];
				b[i]=b[j];
				b[j]=ma;
			}
		}
	}
	for(int i=0;i<s.size();i++)
	{
		cout<<b[i];
	}
	return 0;
} 
