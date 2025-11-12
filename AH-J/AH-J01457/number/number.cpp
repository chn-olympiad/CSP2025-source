#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<ll(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		while(cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
