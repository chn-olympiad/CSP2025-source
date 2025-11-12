//GZ-S00105 贵阳市第三中学 周忠杰  
#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
#define ll long long
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll t=0;
	bool flag=1;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=0;
			t++;
		}
	}
	if(flag==1){
		ll x=1;
		for(ll i=1;i<=n;i++){
			x*=i;
		}
		cout<<x%998244353;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}
