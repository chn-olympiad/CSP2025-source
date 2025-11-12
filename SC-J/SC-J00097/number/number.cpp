#include<bits/stdc++.h>
using namespace std;
string s;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(48<=s[i]&&s[i]<=57){
			t[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}