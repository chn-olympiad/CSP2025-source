#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
map<char,ll>mp;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')mp[s[i]]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=mp[i+'0'];j++)
			cout<<i;
	return 0;
}
