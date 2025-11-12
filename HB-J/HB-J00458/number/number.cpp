#include<bits/stdc++.h>
using namespace std;

int vis[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(size_t i=0;i<s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			vis[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout << i;
			vis[i]--;
		}
	}
	return 0;
}
