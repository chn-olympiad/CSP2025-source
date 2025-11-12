#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,m;
long long dp[300005][20],a[20];
string s;
int bit(int x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long ans=1;
		for(int i=2;i<=n;i++) ans=(ans*i)%mod;
		sort(a+1,a+1+n);
		long long cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=i){
				break;
			}
			if(a[i]==i-1){
				int mmm=1;
				for(int j=2;j<=cnt;j++) mmm=(mmm*j)%mod;
				sum=(sum+mod+mmm)%mod;
				cnt=0;
			}
			cnt++;
		}
		ans=(ans-sum+mod)%mod;
		cout<<ans;
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<(n));i++){
		int k=bit(i);
		for(int j=0;j<=k;j++){
			if(s[k-1]=='0'){
				for(int l=1;l<=n;l++){
					int c=i&(1<<(l-1));
					if( c !=0){
						dp[i][j]=(dp[i][j]+dp[i-(1<<(l-1))][j])%mod;
					}
				}
			}else{
				for(int l=1;l<=n;l++){
					int c=i&(1<<(l-1));
					if( c !=0){
						if(j!=0&&a[l]>=k-j+1){
							//cout<<i<<" "<<j<<endl<<endl;
							dp[i][j]=(dp[i][j]+dp[i-(1<<(l-1))][j-1])%mod;
						}
						if(a[l]<=k-j-1){
							dp[i][j]=(dp[i][j]+dp[i-(1<<(l-1))][j])%mod;
						}
					}
				}
			}
		}
		//cout<<k<<" "<<dp[i][2]<<endl;
	}
	int ans=0,ma=(1<<(n))-1;
	for(int i=m;i<=n;i++){
		ans=(ans+dp[ma][i])%mod;
	}
	cout<<ans;
	return 0;
}/*
3 2
101
1 1 2
*/
