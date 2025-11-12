#include<bits/stdc++.h>
#define int long long
using namespace std;
const int zzz=252525;
const int yyy=25;
string s;
int f[yyy];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9' and s[i]>='0')	f[(s[i]-48)]++;
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++) cout<<i;
	}
	return 0;
}
