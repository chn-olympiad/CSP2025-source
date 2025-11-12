#include<bits/stdc++.h>
using namespace std;
string s,ans;
int cnt[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9')
		cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			ans+=(char)(i+'0');
		}
	}
	cout<<ans;
	return 0;
}
 
