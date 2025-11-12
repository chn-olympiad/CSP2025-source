#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[11];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			w[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(w[i]--){
			cout<<i;
		}
	}
	return 0;
} 