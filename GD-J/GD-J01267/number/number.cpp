#include<bits/stdc++.h>
using namespace std;
bool sttt;
string s;
int t[20];
bool eddd;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('a'<=s[i]) continue;
		t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]--) cout<<char(i+'0');
	}
	cerr<<(&eddd-&sttt)*1.0/1024/1024<<"\n";
	return 0;
}
