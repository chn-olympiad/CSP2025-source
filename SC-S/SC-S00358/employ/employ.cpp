#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=25,mod=998244353;
int n,m;
int a[N],c[N];
int dp[1<<19][N][N];
int lowbit(int x){return x&(-x);}
int cot(int x){
	int js=0;
	while(x){js++;x-=lowbit(x);}
	return js;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;cin>>x;a[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dp[0][0][0]=1;
	for(int S=0;S<(1<<n);S++){
		for(int k=0;k<=n;k++){
			for(int j=0;j<=n;j++){
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1)))continue;
					int T=S|(1<<(i-1));
					int p=k+(a[cot(S)+1]==0||k>=c[i]);
					dp[T][p][j+(p==k)]=(dp[T][p][j+(p==k)]+dp[S][k][j])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=m;j<=n;j++)ans=(ans+dp[(1<<n)-1][i][j])%mod;
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/