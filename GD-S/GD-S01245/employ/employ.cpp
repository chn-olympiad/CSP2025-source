#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int mod=998244353;
bool flag;
int n,m;
int a[N];
string s;
int cnt;
int jie[N];
bool vis[N];
int pai[N];
int ans;
void check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(tmp>=a[pai[i]]){
			tmp++;
			continue;
		}
		if(s[i]=='0')tmp++;
	}
	if(n-tmp>=m)ans=(ans+1)%mod;
	return;
}
void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		pai[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	flag=1;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	jie[0]=1;
	for(int i=1;i<=n;i++)jie[i]=(jie[i-1]*i)%mod;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		if(cnt>0){
			cout<<0<<"\n";
		}else{
			cout<<jie[n]%mod<<"\n";
		}
	}else if(flag){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		if(cnt>n-m){
			cout<<0<<"\n";
		}else{
			cout<<jie[n]<<"\n";
		}
	}else{
		dfs(1);
		cout<<ans%mod<<"\n";
	}
	return 0;
}
