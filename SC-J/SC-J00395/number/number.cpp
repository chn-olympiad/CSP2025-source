#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll number[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(register int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			ll now=s[i]-'0';
			number[now]++;
		}
	}
	for(register int i=9;i>=0;i--){
		ll m=number[i];
		while(m--){
			cout<<i;
		}
	}
	return 0;
}