#include<bits/stdc++.h>
using namespace std;
string s; 
int in[signed(1e6+10)],cnt,tt[15];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i] && s[i]<='9')
			tt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=tt[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
 } 
