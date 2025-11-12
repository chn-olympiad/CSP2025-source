#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
string ans;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//-static-libgcc
	cin >> s;
	for ( int i = 0; i < s.size(); i ++){
		if (isdigit(s[i])){
			ans += s[i];
		}
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout << ans;
	return 0;
}
