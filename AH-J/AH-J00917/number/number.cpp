#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[20+10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[ll(s[i]-'0')]++;
		}
	}
	ll q;
	q=10;
	while(q-- && q!=-1){
		for(ll i=1;i<=cnt[q];i++){
			cout<<q;
		}
	}
	return 0;
}
