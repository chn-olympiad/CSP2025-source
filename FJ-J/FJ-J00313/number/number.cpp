#include<bits/stdc++.h>
using namespace std;
int a[20],l;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			printf("%d",i);
	}
}
