#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll l=s.size()-1;
	for(ll i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	}
	bool flag=0;
	for(ll i=9;i>=0;i--){
		if(t[i]!=0&&i!=0)flag=1;
		if(flag){
			for(ll j=1;j<=t[i];j++)cout<<i;
		}
	}
	if(flag==0)cout<<0;
	return 0;
}
