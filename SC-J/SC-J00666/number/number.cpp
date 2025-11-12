#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
map<int,int> I_have;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if('0'<=s[i] && s[i]<='9') I_have[s[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=I_have[i];j++) cout<<i;
	return 0;
}