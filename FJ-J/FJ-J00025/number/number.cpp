#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	for(int i = 0;i<s.length();++i){
		if('0'<=s[i] && s[i]<='9')++cnt[s[i]-'0'];
	}
	string ans = "";
	for(int i = 9;i>=0;--i){
		for(int j = 0;j<cnt[i];++j){
			ans+=('0'+i);
		}
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
