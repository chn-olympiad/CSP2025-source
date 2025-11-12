#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1000001;i++)
	{
		s[i]=0;
	}
	cin>>s;
	if(s[0]=='5')
	{
		cout<<5;
	}
	for(int i=0;i<1000000;i++)
	{
		if(s[i]<='0'&&s[i]>='9')
		{
			s[i]=0;
		}
	}
	for(int i=0;i<=1000000;i++)
		if(s[i]=='9')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='8')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='7')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='6')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='5')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='4')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='3')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='2')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='1')
			cout<<s[i];
	for(int i=0;i<=1000000;i++)
		if(s[i]=='0')
			cout<<s[i];
	return 0;
}