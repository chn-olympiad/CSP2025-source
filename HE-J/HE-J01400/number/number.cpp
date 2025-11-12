#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[500050];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(sum[i]!=0)
		for(int j=1;j<=sum[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
