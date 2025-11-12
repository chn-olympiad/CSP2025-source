#include<bits/stdc++.h>
using namespace std;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
