#include<bits/stdc++.h>
using namespace std;
#define int long long
//const int maxn=1e5+10;
string s;
int num[10];
void solve1(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]--)cout<<i;
	}
}
void solve(){
	if(1)solve1();
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
