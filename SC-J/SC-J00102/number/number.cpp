#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;int mp[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(!mp[i])continue;
		for(int j=1;j<=mp[i];j++)cout<<i;
	}
	return 0;
}