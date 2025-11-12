#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N=3e3+100,M=1e5+100,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
int n,m,t,k;
int a[N];
ll ans=0;
string s;
int work1(){
	int res=1;
	for(int i=1;i<=n;i++)res=res%mod*i%mod;
	return res%mod;
}
int work2(){
	int res=1;
	for(int i=1;i<n;i++)res=res%mod*i%mod;
	return res%mod;
}
bool vis[N];
void dfs(int x,int su){
	if(x==n){
		if(n-su>=m)ans=(ans+1)%mod;
		return;
	}
	if(n-su<m)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int k=0;
			if(s[x]=='0'||su>=a[i])k=1;
			dfs(x+1,su+k);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	int y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])y++;
	}	
	if(s.find("0")==-1){
		cout<<work1();
		return 0;
	}
	if(m==1){
		cout<<work2()%mod*y%mod;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}
