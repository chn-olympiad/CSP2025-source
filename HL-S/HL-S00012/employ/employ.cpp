#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[510],p[510],b[510],s[510],q[510],fac[510],inv[510];
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1,inv[0]=1;
	for(int i=1;i<=500;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
	int n,m,cnt=0,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		a[i]=c-'0';
		if(a[i]) q[++cnt]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s[b[i]]++;
	}
	for(int i=n;i>=0;i--) s[i]=s[i]+s[i+1];
	for(int S=0;S<=(1<<cnt)-1;S++){
		for(int i=1;i<=cnt;i++) p[i]=((S>>(i-1))&1);
		int t=0,res=1,k=0;vector<int> v;
		for(int i=1;i<=cnt;i++){
			if(p[i]==0) v.push_back(n);
			else{
				v.push_back(s[q[i]-t]);
				t++;
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<(int)v.size();i++) res=res*(v[i]-i)%mod;
		for(int i=0;i<=t-m;i++){
			if((i&1)==0) k=k+fac[t-m]*inv[i]%mod*inv[t-m-i]%mod,k%=mod;
			else k=k-fac[t-m]*inv[i]%mod*inv[t-m-i]%mod,k+=mod,k%=mod;
		}
		ans=ans+res*k%mod,ans+=mod,ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}
//Wo shi chang zhui yi guo qu...
//Wo gai zai na li ting liu ,wo wen wo zi ji.