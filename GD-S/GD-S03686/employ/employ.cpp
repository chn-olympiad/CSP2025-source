#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=998244353;
ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if(b%2){
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return res;
}
ll a[505],inv[505];
void init(){
	a[1]=inv[1]=1;
	for(int i=2;i<=500;i++){
		a[i]=a[i-1]*i;
		inv[i]=ksm(a[i],mod-2);
	}
}
ll C(ll n,ll m){
	return a[n]*inv[m]%mod*inv[n-m]%mod;
}
//--------------------------------
int n,m,cnt0[505],c[505];
string s;
void solve1(){
	int p[505];
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	ll ans=0;
	do{
		int res=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')cnt++;
			else{
				if(cnt>=c[p[i]])cnt++;
				else res++;
			}
		}
		if(res>=m)ans++;
		ans%=mod;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
}
void solveA(){
	
}
int main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cnt0[i]=cnt0[i-1]+(bool)(s[i]=='0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(n<=18)solve1();
	else if(cnt0[n]==0){
		solveA();
	}
	return 0;
}
