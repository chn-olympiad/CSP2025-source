#include<bits/stdc++.h>
//#define long long long long
using namespace std;
long long dp[20][1<<20];
const long long mod=998244353;
long long n,m;
char s[1000000];
long long c[1000000];
bool f[1000000];
long long ans=0;
void dfs(long long u,long long sum){
//	cout<<sum<<"\n";
	if(sum>n-m)return;
	if(u>n){
		
		ans=(ans+1)%mod;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		if(s[u]=='0'||sum>=c[i]){
			dfs(u+1,sum+1);
		}else{
			dfs(u+1,sum);	
		}
		f[i]=0;
	}
}
long long inc[1000010];
void init(long long N){
	inc[0]=1;
	for(long long i=1;i<=N;i++)inc[i]=inc[i-1]*i%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>s[i];
	for(long long i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1,0);
		cout<<ans;
	}else{
		cout<<0<<"\n";
//		init(10000);
//		long long sum=0;
//		for(long long i=1;i<=n;i++)if(c[i]==0)sum++;
//		if(sum>m)cout<<0<<"\n";
//		else cout<<inc[n]<<"\n";
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

