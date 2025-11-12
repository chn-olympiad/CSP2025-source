#include<iostream>
using namespace std;
const int mod=998244353;
int s[502],c[502];
int sp[502];
void init(){
	sp[0]=1;
	for(int i=1;i<=500;i++)sp[i]=1LL*sp[i-1]*i%mod;
}
int fp(int a,int b){
	if(b==0)return 1;
	a%=mod;
	int t=fp(a,b/2);
	return b&1?1LL*t*t%mod*a%mod:1LL*t*t%mod;
}
int ie(int a){
	return fp(a,mod-2);
}
int A(int n,int k){
	return 1LL*sp[n]*ie(sp[n-k])%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    init();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=(c-'0');
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	cout<<A(n,n);
	return 0;
}
