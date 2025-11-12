#include<bits/stdc++.h>
#define int long long
#define N (int)(15)
using namespace std;
int b[N];
inline void read(int &num);
inline void solve();
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
inline void solve(){
	string str;
	cin>>str;
	int slen=str.size();
	for(int i=0;i<slen;++i){
		char c=str[i];
		if(c>='0'&&c<='9'){
			++b[c-'0'];
		}
	}
	for(int i=9;i>=0;--i){
		while(b[i]){
			cout<<i;
			--b[i];
		}
	}
}
