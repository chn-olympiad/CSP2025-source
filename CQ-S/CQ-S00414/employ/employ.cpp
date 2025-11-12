#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string str;
long long fpow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int n,m;
int cnt[505];
long long fac[505],dp[505][505];
long long C(long long a,long long b){
	if(a<0||b<0||a<b)return 0;
	return fac[a]*fpow(fac[b]*fac[a-b]%mod,mod-2)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>str;str=" "+str;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	if(m==n){
		for(int i=1;i<=n;i++){
			if(str[i]=='0'){
				cout<<"0\n";
				return 0;
			}
		}
		if(cnt[0]!=0){
			cout<<"0\n";
			return 0;
		}
		cout<<fac[n]<<"\n";
		return 0;
	}
	dp[0][cnt[0]]=1;
	int sum=cnt[0];
	for(int i=1;i<=n;i++){
		sum+=cnt[i];
		for(int j=0;j<=n;j++){
			for(int k=0;k<=cnt[i];k++){
				if(j+k>n)continue;
				if(j<i&&k!=0)continue;
				if(sum<j)continue;
				if(j<i){
					dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*C(sum,cnt[i])%mod)%mod;
				}else{
					dp[i][j+cnt[i]-k]=(dp[i][j+cnt[i]-k]+1ll*dp[i-1][j]*C(sum-j+i-1-(cnt[i]-k),k)%mod*C(j+cnt[i]-k-(i-1),cnt[i]-k)%mod)%mod;
				}
			}
		}
	}
	long long ans=0;
	for(int j=0;j<=n-m;j++)ans=(ans+dp[n][j])%mod;
	for(int i=0;i<=n;i++)ans=ans*fac[cnt[i]]%mod;
	cout<<ans<<'\n';
}
