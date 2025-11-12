#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long GD=988244353;
ll n,m,cnt,br[111],q[111],an;
string s;
ll timm(ll x){
	if(x==0)	return 0;
	if(x==1)	return 1;
	if(x==2)	return 2;
	ll ans=1;
	for(ll i=2;i<=x;i++){
		ans=ans*i;
		ans%=GD;
		cout<<ans<<endl;
	}
	return ans;
}
ll c(ll x,ll y){
	if(x==y)	return 1;
	ll ans=1;
	for(ll i=y;i<=x;i++){
		ans=ans*i%GD;
	}
	ans/=timm(x-y);
	ans=ans%GD;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>br[i];
	}
	for(ll i=0;i<s.length();i++){
		if(s[i]=='1'){cnt++;}
	}
	if(cnt==n){
		for(ll j=m;j<=n;j++){
			an=an+c(n,j);
		}
		cout<<an;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
