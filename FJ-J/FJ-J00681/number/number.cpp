#include<bits/stdc++.h>
using namespace std;
char s2[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	int m=0,t,c=0,l=0,p=1;
	while((s1[c]>='0'&&s1[c]<='9')||(s1[c]>='a'&&s1[c]<='z'))
	{
		l++;
		c++;
	}
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(s1[j]>='0'&&s1[j]<='9')
			{
				if(s1[j]-'0'>=m)
				{
					m=s1[j]-'0';
					t=j;
					p=0;
				}
			}
		}
		s1[t]='a';
		if(p==0)s2[i]=m+'0';
		m=0;
		p=1;
	}
	for(int i=0;i<l;i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')cout<<s2[i];
	}
	return 0;
}