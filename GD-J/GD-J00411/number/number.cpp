#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(ll i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[x[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=0;j<a[i];j++){
			cout<<i;
		}
	}
	
	
	return 0;
} 
