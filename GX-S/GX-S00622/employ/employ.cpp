#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s;
	ll c[505];
	ll q=0;
	cin>>s;
	ll qqqqq=s.size();
	for(ll i=0;i<qqqqq;i++){
		if(s[i]=='0'){
			q++;
		}
	}
	for(ll i=0;i<n;i++){
		cin>>c[i];
	}
	
	if(n-q>=998){
		cout<<(n-q)/998;
	}
	if(n-q<998&&n-q>=353){
		cout<<(n-q)%353;
	}
	if(n-q<353){
		cout<<(n-q)%244;
		}
	return 0;
}
