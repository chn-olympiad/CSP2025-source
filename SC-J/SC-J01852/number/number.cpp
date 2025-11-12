#include<bits/stdc++.h>
using  namespace std;
string s;
int a[105],c=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			a[c]=int(s[i])-48;
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--)
	{
		printf("%d",a[i]); 
	}
	return 0;
}