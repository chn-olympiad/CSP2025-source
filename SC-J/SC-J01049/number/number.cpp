#include<bits/stdc++.h>
using namespace std;

int sum[100];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			sum[s[i]-'0']++;
		}
	}
	string ans;
	for(int i=9;i>=0;i--)
	{
		while(sum[i])
		{
			ans+=char(i+'0');
			sum[i]--;
		}
	}
	cout<<ans;
	return 0;
}