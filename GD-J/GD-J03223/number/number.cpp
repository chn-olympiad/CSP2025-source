#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string n;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	ll len=n.size();
	for(ll i=0;i<len;++i){
		if(n[i]>='0' && n[i]<='9'){
			ll t=n[i]-'0';
			a[t]++;
		}
	}
	for(ll i=9;i>=0;--i){
		ll t=a[i];
		while(t--)
			cout<<i;
	}
	
	
	return 0;
} 
