#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,a[505],opt=-1;
string str;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<str.size();i++){
		if(str[i]=='0'){
			opt=2;break;
		}
	}
	if(opt==-1) opt=1;
	if(opt==1){
		ll ans=1;
		for(int i=n;i>(n-m);n--){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		ll can=-1;
		for(int i=0;i<str.size();i++){
			if(str[i]=='1') can=i+1;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++){
			if(a[i]>=can){
				cout<<(n-i+1)%mod<<endl;
				return 0;
			}
		}
	}
	return 0;
}
