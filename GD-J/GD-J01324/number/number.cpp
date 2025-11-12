#include<bits/stdc++.h>
using namespace std;
string s; 
int mp[12];
int flag=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    memset(mp,0,sizeof(mp));
    cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int a=s[i]-48;
		if(a>=0&&a<=9)
		{
			mp[a]++;
		//	cout<<s[i]<<" "<<s[i]-'0';
		}
	} 
	for(int i=9;i>=1;i--)
	{
		if(mp[i]) 
		{
			flag=1;
			for(int j=1;j<=mp[i];j++) cout<<i;
		}
	}
	if(flag)
	{
		if(mp[0])
		{
				for(int j=1;j<=mp[0];j++) cout<<0;
		}
	}
	return 0;
 } 
