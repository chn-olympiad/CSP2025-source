#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int c[N],s[N],dp[(1<<18)+5][20];
int pcnt(int x){
	int ans=0;
	while(x){
		ans+=x&1;
		x>>=1;
	}
	return ans;
}
int n,m;
bool chk(){
	for(int i=1;i<=n;i++)if(!s[i])return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
	}
	if(chk()&&n>20){
		int ans=1;
		for(int i=1;i<=n;i++)(ans*=i)%=mod;
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=0;i<n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int p=pcnt(i);
		for(int j=0;j<n;j++){
			if((1<<j)&i)continue;
			int nxt=(1<<j)|i;
			for(int k=0;k<n;k++){
				if(c[j]>p-k&&(s[p+1])){
					(dp[nxt][k+1]+=dp[i][k])%=mod;
				}
				else (dp[nxt][k]+=dp[i][k])%=mod;
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)(ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans<<"\n";
}