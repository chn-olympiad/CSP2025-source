#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+4,mod=998244353;
string s;
int n,m,c[N],dp[(1<<20)][30],ans;
int count(int x){
	int sum=0;
	while(x){
		if(x%2)sum++;
		x/=2;
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(false); 
	cin.tie(0),cout.tie(0);
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i]; 
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		int cnt=count(i);
	//	cout<<i<<" "<<cnt<<"\n";
		for(int j=0;j<n;j++){
			if((1<<j)&i)continue;
			for(int k=0;k<=n;k++){
				if(k<c[j]&&s[cnt]=='1'){
					dp[i^(1<<j)][k]+=dp[i][k];
					dp[i^(1<<j)][k]%=mod; 
				//	cout<<1<<" "<<(i^(1<<j))<<" "<<k<<" "<<dp[i^(1<<j)][k]<<"\n";
				}
				else{
					dp[i^(1<<j)][k+1]+=dp[i][k];
					dp[i^(1<<j)][k+1]%=mod;
			//		cout<<2<<" "<<(i^(1<<j))<<" "<<k+1<<" "<<dp[i^(1<<j)][k+1]<<"\n";
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++){
	//	cout<<n-i<<" "<<dp[(1<<n)-1][i]<<"\n";
		ans+=dp[(1<<n)-1][i];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
