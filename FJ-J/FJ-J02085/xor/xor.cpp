#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5; 
int n,k,tmp;
int a[N],dp[N],s[N][30];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++)
			s[i][j]=s[i-1][j]+((a[i]>>j)&1);
		tmp=max(tmp,a[i]);
	}
	if(tmp==1&&n>1e5){
		int cnt=0,ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt=0;
					ans++;
					continue;
				}
				cnt++;
				if(cnt%2==0){
					cnt=0;
					ans++;
				}
			}
			cout<<ans;	
			return 0;		
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			int sum=0;
			for(int t=0;t<30;t++)
				sum+=(s[i][t]-s[j-1][t]+2)%2*(1<<t);
			//cout<<j<<' '<<i<<' '<<sum<<'\n'; 
			if(sum==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}

