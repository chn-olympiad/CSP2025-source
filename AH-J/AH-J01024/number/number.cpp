#include<bits/stdc++.h>
using namespace std;
#define int long long
int m[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			m[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=m[i];j++)
			cout<<i;
	}
	cout<<"\n";
	return 0;
}
