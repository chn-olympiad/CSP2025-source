#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005]={};
int t=0;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			c[t++]=s[i];
		}
	}
	sort(c,c+t,cmp);
	for(int i=0;i<=t;i++)
	{
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
