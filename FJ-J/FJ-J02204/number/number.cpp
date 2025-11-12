#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
ll t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (ll i=0;i<a.size();i++){
		if ('0'<=a[i] and a[i]<='9'){
			t[a[i]-48]++;
		}
	}
	for (ll i=10;i>=0;i--){
		for (ll j=0;j<t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
