#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;
	cin>>s;
	string ans;
	for(int i=0;i<s.size();i++)
	if(s[i]<='9'&&s[i]>='0')
	ans+=s[i];
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}

// Tiat Siba
