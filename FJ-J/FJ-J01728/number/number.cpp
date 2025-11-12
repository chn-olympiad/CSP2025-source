#include<bits/stdc++.h>
using namespace std;
int n,t,pd,num[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length()-1;
	for(int i=0;i<=n;i++) 
	{
		if(s[i]>='0' && s[i]<='9')
		{
			t=s[i]-'0';
			num[t]++;	
		}	
	} 
	for(int i=9;i>=1;i--)
	{
		if(num[i])
		{
			for(int j=1;j<=num[i];j++) cout<<i;
			pd=1;
		}
	}
	if(pd==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=num[0];i++)
		{
			cout<<0;
		}
	}
	return 0;
} 
