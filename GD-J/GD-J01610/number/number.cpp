#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=9;i>=0;i--)
	{
		if(flag==0&&i==0)
		{
			printf("%d",0);
			return 0;
		}
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
			flag=1;
		}
	}
	return 0;
}  
