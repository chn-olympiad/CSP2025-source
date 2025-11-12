#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,ans;
int a[N];
int dp[(1<<19)][N];
string b;
int Cnt(int x){
	int res=0;
	while(x) x=x&(x-1),res++;
	return res;
}
void add(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tot=(1<<n);
	dp[0][0]=1;
	for(int s=1;s<tot;s++){
		int cnt=Cnt(s);
		for(int j=1;j<=n;j++)
			if(s>>(j-1)&1){
				for(int k=0;k<=cnt;k++){
					if(cnt-k-1>=a[j]||b[cnt-1]=='0') add(dp[s][k],dp[s^(1<<(j-1))][k]);
					if(k&&cnt-k<a[j]&&b[cnt-1]=='1') add(dp[s][k],dp[s^(1<<(j-1))][k-1]);
				}
			}
	}
	for(int i=m;i<=n;i++)
		add(ans,dp[tot-1][i]);
	cout<<ans; 
	return 0;
} 
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
