#include<bits/stdc++.h>
using namespace std;
int sz[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			sz[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(sz[i]>=1)
		{
			for(int j=1;j<=sz[i];j++)
			{
				printf("%d",i);
			}
		}
	}
	
	
	return 0;
}
