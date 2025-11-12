#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> mp;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,h;
	cin>>s;
	long long int lens=s.size();
	for(long long int i=0;i<lens;i++)
	{
		for(long long int j='0';j<='9';j++)
		{
			if(s[i]==j)
			{
				mp[j-'0']++;
			}
		}
	}
	for(long long int i=9;i>=0;i--)
	{
		for(long long int j=1;j<=mp[i];j++)
		{
			cout<<i;
		}
	}
}
