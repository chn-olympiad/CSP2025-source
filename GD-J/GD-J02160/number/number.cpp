#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15],su;
bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-'0']++;
			su++;
			if(s[i]^'0'){
				f=1;
			}
		}
	}
	if(!su||!f){
		cout<<0;
		return 0;
	}
	for(int i=9;i>-1;i--){
		for(int j=0;j<cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
