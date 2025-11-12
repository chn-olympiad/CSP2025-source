#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353,MAXN=262144+5;
int n,m,ans;
string s;
int c[N];
bool vis[N];
int p[N];
bool check(){
	int cnt=0;
	int qt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') qt++;
		else{
			if(c[p[i]]<=qt) qt++;
			else cnt++;
		}
	}
	return (cnt>=m);
}
void dfs(int dep){
	if(dep==n){
		if(check())
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			p[dep+1]=i;
			dfs(dep+1);
			vis[i]=0;
		}
}
void sub1(){
	dfs(0);
	cout<<ans;
}
void sub3(){
	ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans*i)%mod;
	cout<<ans;
}
int dp[N][MAXN];
void sub2(){
	dp[0][0]=1;
	for(int S=0;S<(1<<n);S++){
		int cnt1=__builtin_popcount(S);
		for(int i=0;i<=n;i++){
			//cout<<"i="<<i<<" S="<<S<<" "<<dp[i][S]<<"\n";
			for(int j=0;j<n;j++){
				if((S|(1<<j))==S) continue;
				int T=S|(1<<j);
				if(cnt1-i>=c[j+1] || s[cnt1+1]=='0'){
					dp[i][T]+=dp[i][S];
					dp[i][T]%=mod;
				}
				else{
					dp[i+1][T]+=dp[i][S];
					dp[i+1][T]%=mod;
				}
			}
		}
	}
	for(int i=m;i<=n;i++)
		ans=(ans+dp[i][(1<<n)-1])%mod;
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='0'){
			flag=0;
			break;
		}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1') cnt++;
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		//cout<<"sub2\n";
		sub1();
	}
	else if(n<=18){
		//cout<<"sub2\n";
		sub2();
	}
	else if(flag){
		//cout<<"sub3\n";
		sub3();
	}
	else if(n==m){
		//cout<<"sub3\n";
		sub3();
	}
	else{
		//cout<<"sub1\n";
		sub2();
	}
	return 0;
}