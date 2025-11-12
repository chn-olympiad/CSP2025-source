#include<bits/stdc++.h>
#define	ll long long
ll f(ll n){
	ll p=1;
	for(ll i=1;i<=n;i++){
		p*=i;
	}
	return p;
}
const int N=1e4+10;
ll n,m,c;
char s[N],c2[N];
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=n;i++) cin>>c2[i];
	for(ll i=1;i<=n;i++){
		if(s[i]=='1') c++;
	}	
	if(c==n)
	{
		cout<<f(m)/f(n)%998244353;
		return 0;
	 } 
	if(m==1){
		cout<<f(m)/f(c)%998244353;
		return 0;
	}
	if(m==n){
		cout<<f(c)%998244353;
		return 0;
	}
	return 0;
} 