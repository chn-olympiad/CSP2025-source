#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n[s.length()];
	int j=0,g=0;
	for(int i=0;i<s.length();i++)
	{
		int ss=s[i]-'0';
		if(ss<='9')
		{	
			n[j]=s[i]-'0';
			j++;
			g++;
			
		}
	}
	int nn=0;
	while(g--)
	{
		int zd=0,ii=0,sf=0;
		for(int i=0;i<s.length();i++)
		{
			if(n[i]<=9)
				if(zd<=n[i])
				{
					sf=1;
					zd=n[i];
					ii=i;
				}
		}
		if(sf==1)
		{	n[ii]=99;
			nn=nn*10+zd;
		}
	}
	cout<<nn;
	return 0;
}
