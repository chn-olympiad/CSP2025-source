#include<bits/stdc++.h>
using namespace std;
const int N=505,Mod=998244353;
int n,m;
string s;
int c[N];
bool check1(){
	for(int i=0;i<n;i++){
		if(s[i]=='0')
			return false;
	}
	return true;
}
void solve1(){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%Mod;
	}
	cout<<ans;
}
void solve2(){
	if(s[0]=='1'){
		solve1();
		return;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(c[i]>0)ans++;
	}
	for(int i=1;i<n;i++){
		ans=ans*i%Mod;
	}
	cout<<ans;
}
void solve3(){
	cout<<0;
}
long long fac[N];
bool vis[N];
long long dfs(int now,int t){
	if(t==m){
		return fac[n-now+1];
	}
	if(now>n)return 0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(s[now-1]=='1'&&c[i]>=now-t)ans=(ans+dfs(now+1,t+1))%Mod;
		else ans=(ans+dfs(now+1,t))%Mod;
		vis[i]=0;
	}
	return ans;

}
void solve4(){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%Mod;
	}
	cout<<dfs(1,0);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(check1()){
		solve1();
	}else if(m==1){
		solve2();
	}else if(m==n){
		solve3();
	}else if(n<=18){
		solve4();
	}
	return 0;
}
//100+72+100+44=316
//luogu_id=943211
//17:53 finish