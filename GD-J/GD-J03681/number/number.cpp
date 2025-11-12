#include<bits/stdc++.h>
#define i64 long long
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7;
void solve();
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	string s;
	cin>>s;
	int ln=s.size();
	for(int i=0;i<ln;i++){
		if(s[i]>='a' && s[i]<='z'){
			s[i]=' ';
		}
	}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	while(s.find(' ')!=string::npos){
		s.erase(s.find(' '),1);
	}
	cout<<s;
}

