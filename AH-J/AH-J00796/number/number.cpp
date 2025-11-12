#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int d[11];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			d[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=d[i];j++)
		{
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
