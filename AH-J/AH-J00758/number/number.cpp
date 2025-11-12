#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
string s;
ll f[N];
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
		   	ll j=s[i]-'0';
		   	f[j]++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=f[i];j++){
			cout<<i;
		}
	}
	return 0;
}
