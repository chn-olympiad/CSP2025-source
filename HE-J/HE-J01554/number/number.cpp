#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[20];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=a[i];j>0;j--)
			cout<<i;
	return 0;
}
