//CSP 2025 RP++
#include <bits/stdc++.h>
#define N 510
#define int long long
using namespace std;
const int mod = 998244353;
int n,m,c[N];
int fac[N],inv_fac[N];
string s;
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv_fac[n+1]=1;
	for(int i=n;i>=1;i--){
		inv_fac[i]=inv_fac[i+1]*qpow(i,mod-2)%mod;
	}
}
int C(int a,int b){
	if(b>a||!b) return 0; 
	return fac[a]*inv_fac[b]%mod*inv_fac[a-b]%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) cnt1++;
		else cnt2++;
	}
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=0; break;
		}
	}
	if(flag){
		cout<<C(cnt1,m)<<endl;
	}
	return 0; 
}
