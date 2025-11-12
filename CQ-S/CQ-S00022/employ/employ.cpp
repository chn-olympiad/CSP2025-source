#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int Fact[505],Inv[505],cnt[505],q0[505],q1[505],qc[505];
int n,m,c[505];
char s[505];
inline int Pow(int a,int v){
	int ans=1;
	while(v>0){
		if(v&1)ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod,v=v>>1; 
	}return ans;
}
inline int C(int n,int m){
	return (n<m||n<0||m<0?0:1ll*Fact[n]*Inv[m]%Mod*Inv[n-m]%Mod);
}
inline int A(int n,int m){
	return (n<m||n<0||m<0?0:1ll*Fact[n]*Inv[n-m]%Mod); 
}
int dp[205][205][205],p[105];
int ans; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Fact[0]=1;for(int i=1;i<=500;i++)Fact[i]=1ll*Fact[i-1]*i%Mod; 
	Inv[500]=Pow(Fact[500],Mod-2);for(int i=499;i>=0;i--)Inv[i]=1ll*Inv[i+1]*(i+1)%Mod;
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)p[i]=i;
	int ans=0;
	while(true){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i]=='0')cnt++;
		}
		if(cnt<=n-m)ans++;
		if(!next_permutation(p+1,p+n+1))break;
	} 
	printf("%d",ans);
	return 0;
}
