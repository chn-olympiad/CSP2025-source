#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353 
using namespace std;
string s;
ll n,m,ans,cnt;
ll w[100010];
ll f(ll a){
	if(a==0){
		return 1;
	}
	return (a%mod)*((a-1)%mod);
}
ll A(ll a,ll b){
	return (f(a)%mod)/(f(a-b)%mod);
}
void c(string s){
	if(s[i]=='1'){
		cnt++;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>s;
	c(s);
	for(int i=0;i<n;i++){
		scanf("%lld",&w[i]);
	}
	if(m==1||cnt==n){
		ans=A(n,n);
	}
	if(m==n){
		ans=0;
	}
	printf("%lld",ans);
	return 0;
}
