#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num[11];
	memset(num,0,sizeof(num));
	cin>>s;
	for(int i=0;i<=s.length();i++)
	{
		if(isdigit(s[i]))
		{
			num[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0)
		{
			cout<<i;
			num[i]--;
		} 
	}
} 
