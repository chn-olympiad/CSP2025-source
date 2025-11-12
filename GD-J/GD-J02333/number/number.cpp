#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0}; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0)
		{
			for(int j=0;j<a[i];j++)
			{
				cout<<i;
			}	
		} 
	}
	return 0;
} 
