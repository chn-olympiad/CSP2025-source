#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt[10]={};
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]>0){
			while(cnt[i]--){
				cout << i;
			}
		}
	}
	return 0;
}
