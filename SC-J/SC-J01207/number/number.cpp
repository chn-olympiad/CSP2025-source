#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
int flag[15];

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
		if(s[i]<'0'||s[i]>'9')
			continue;
		flag[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(flag[i])
		{
			cout<<i;
			flag[i]--;
		}
	}
	
	return 0;
}