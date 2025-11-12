#include <bits/stdc++.h>
using namespace std;
string s;
long long shuzi[11]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			shuzi[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--)
	{
		if(shuzi[j]!=0)
		{
			for(int i=0;i<shuzi[j];i++)
			{
				cout<<j;
			}
		}
	}
	return 0;
	
 } 
