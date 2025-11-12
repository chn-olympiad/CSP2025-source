#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define lowbit(x) (x&-x)
int n,m;
char s[505];
int dp[(1<<20)+5][20],sz[(1<<20)+5],c[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(m==n){
		bool F=true;
		int power=1;
		for(int i=0;i<n;i++){
			if(c[i]==0||s[i]=='0')F=false;
			power=((long long)power)*(i+1)%mod;
		}
		if(F)cout<<0;
		else cout<<power;
	}
	else{
		dp[0][0]=1;
		for(int S=0;S<(1<<n);S++){
			if(S)sz[S]=sz[S-lowbit(S)]+1;
			for(int j=0;j<=n;j++){
				for(int k=0;k<n;k++){
					if(S&(1<<k))continue;
					dp[S|(1<<k)][j+((c[k]<=j)||(s[sz[S]]=='0'))]+=dp[S][j];
					dp[S|(1<<k)][j+(c[k]<=j)]%=mod;
				}
			}
		}
		int answer=0;
		for(int k=0;k<=n;k++){
			if(n-k>=m){
				answer=(answer+dp[(1<<n)-1][k])%mod;
			}
		}
		cout<<answer;
	}
	return 0;
}
