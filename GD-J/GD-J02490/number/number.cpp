#include<bits/stdc++.h>
using namespace std;
int cnt[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0;i<s.length();i++){
		if(s[i] >= '0'&&s[i]<='9'){
			cnt[s[i] - '0'] ++;
		}
	}
	for(int i = 72;i >= 0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
} 
