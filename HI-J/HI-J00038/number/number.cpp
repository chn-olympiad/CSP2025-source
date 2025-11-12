#include<bits/stdc++.h>
using namespace std;

int sz[9];
char s[1000000];

int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	cin >> s;
	
	for(int i  = 0 ; i < strlen(s) ; i ++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			sz[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		if(sz[i])
		{
			for(int j=0;j<sz[i];j++)
			{
				cout<<i;
			}
		}
	}
	
 	return 0;
}

