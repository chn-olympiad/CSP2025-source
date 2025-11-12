#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	for(ll i=9;i>=0; ){
		if(a[i]>0){
			cout<<i;
			a[i]--;
		}
		else i--;
	}
	return 0;
}
