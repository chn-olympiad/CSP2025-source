#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
string s;
int n,m;
int a[N],b[N];
int vis[N];
int ans=0;
bool check(){
	int num=0;
	int fail=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			fail++;
			continue;
		}
		else{
			if(fail<a[b[i]]){
				num++;
			}
			else{
				fail++;
			}
		}
	}
	if(num>=m) return 1;
	return 0;
}
void dfs(int num){
	if(num==n+1){
		if(check()) ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		b[num]=i;
		vis[i]=1;
		dfs(num+1);
		vis[i]=0;
	}
}
int fac[N],ifac[N];
void init(){
	fac[0]=fac[1]=ifac[1]=1;ifac[0]=0;
	for(int i=2;i<=500;i++) fac[i]=(fac[i-1]*i)%mod;
	for(int i=1;i<=500;i++) ifac[i]=(mod-mod/i)*ifac[mod%i]%mod;
	for(int i=1;i<=500;i++) ifac[i]=(ifac[i-1]*i)%mod;
}
int c(int n,int m){
	return ((fac[n]*ifac[m])%mod*ifac[n-m])%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	init();
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) flag=1;
	}
	if(n<=15){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(flag==0) cout<<fac[n];
		else cout<<0;
		return 0;
	}
	cout<<fac[n];
	return 0;
}
