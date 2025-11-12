#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll len,c[110];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(ll i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9') c[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		if(c[i]>0){
			for(ll j=1;j<=c[i];j++) printf("%lld",i);
		}
	}
	return 0;
}
