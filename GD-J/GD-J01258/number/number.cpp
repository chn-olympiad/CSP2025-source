#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

bool check(char a){
	if(a-'0'>=0&&a-'0'<=9) return 1;
	else return 0;
}

void solve(){
	string s;
	cin>>s;
	unordered_map<int,int> mp;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if(check(s[i])){
			mp[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<mp[i];j++){
			cout<<i;
		}
	}
	return;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	solve();
	return 0;
} 
