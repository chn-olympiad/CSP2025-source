#include<bits/stdc++.h>
using namespace std;
int i,j,n=0,b[50];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s[1]==' ')
	{
		if(s[0]>='0'&&s[0]<=9)
		cout<<s[0];
		return 0;
	}
	for(int i=0;s[i]!=' ';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
