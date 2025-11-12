#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll n;
ll num[23];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
	n=a.size();
	a=" "+a;
	for(ll i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[a[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
