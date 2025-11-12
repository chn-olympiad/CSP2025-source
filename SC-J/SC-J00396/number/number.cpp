#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;--i)if('0'<=s[i]&&s[i]<='9')cout<<s[i];
	return 0;
}