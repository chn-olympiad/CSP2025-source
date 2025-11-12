#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll jl[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			jl[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=0;j<jl[i];j++) putchar(i+'0');
	}
	return 0;
}
