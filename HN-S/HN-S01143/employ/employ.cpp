#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=18,mod=998244353,M=505;
int dp[2][1<<N][N+2],n,m,a[M],h[M];
string s;
void add(int &a,int b){
	a=(a+b>=mod?a+b-mod:a+b);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	h[0]=0;
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]+s[i]-'0';
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(h[n]<m){
		cout<<0;
		return 0;
	}
	if(n<=18){
		dp[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++)
				for(int l=0;l<=h[i];l++){
					for(int k=0;k<n;k++){
						if((j>>k)&1) continue;
						
						if(i-l<a[k]&&s[i+1]=='1')
							add(dp[~i&1][j^(1<<k)][l+1],dp[i&1][j][l]);
						else 
							add(dp[~i&1][j^(1<<k)][l],dp[i&1][j][l]);
					}
				}
			for(int j=0;j<(1<<n);j++)
				for(int l=0;l<=h[i];l++){
					dp[i&1][j][l]=0;
				}
	
		}	
		int ans=0;
		for(int i=m;i<=h[n];i++){
			add(ans,dp[n&1][(1<<n)-1][i]);
		}
		cout<<ans;
		return 0;
	}
	if(n==m||h[n]==n){
		for(int i=0;i<n;i++)
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans*=i;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
/*
3 2
101
1 1 2
*/
