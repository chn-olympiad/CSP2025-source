#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll a[10];
string s;
int main(){
	cin>>s;
	ll n=s.length();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}	
	for(ll i=9;i>=0;i--){
		if(a[i]){
			for(ll j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
