#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int l[5888];
bool vis[5888];
void dfs(int he,int mx,int st,int cnt){
	if(cnt>=3&&he>mx*2) ans++;
	for(int i=st;i<=n;i++){
		dfs(he+l[i],max(mx,l[i]),i+1,cnt+1);
	}
	return;
}
void solve1(){
	dfs(0,0,1,0);
	cout<<ans%mod;
}
int abc(int x){
	int ret=1;
	if(x>n-x) x=n-x;
	int j=1,ch;
	for(int i=n-x+1;i<=n;i++){
		ch=i;
		while(j<x&&ch%j==0) ch/=j;
		ret*=ch;
		ret%=mod;
	}
	return ret;
}
void solve2(){
	for(int i=3;i<=n;i++){
		ans+=abc(i);
		ans%=mod;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	if(n>20) solve2();
	else solve1();
	return 0;
}
