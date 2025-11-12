#include<bits/stdc++.h>
using namespace std;
string s;
int len,ans[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	len=s.length();
	for(int i=0; i<len; i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			int p=s[i]-'0';
			ans[p]+=1;
		}
	}
	for(int i=9; i>=0; i--)
	{
		if(ans[i]!=0)
		{
			for(int j=1; j<=ans[i]; j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
} 
