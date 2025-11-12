#include<bits/stdc++.h>
using namespace std;
string s;
bool compare(string a,string b){
	return a==b;
}
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			ans[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ans[i]){
			cout <<i;
			ans[i]--;
		} 
	}	
	return 0;
} 
