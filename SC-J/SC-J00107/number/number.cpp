#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9) t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++) cout<<i;
	}
	return 0;
}