#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			cnt[s[i]-'0']++; 
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
