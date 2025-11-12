#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bool bb;
typedef double dd;
typedef string ss;
typedef void vv;
ll a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ss s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
