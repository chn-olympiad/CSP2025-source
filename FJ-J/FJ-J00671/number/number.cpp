#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[110],l;
string s; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l=s.size();
	for (int i=0;i<l;i++)
	{
		if (s[i]>='0' && s[i]<='9') t[s[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=0;j<t[i];j++) cout<<i;
	}
	return 0;
}

