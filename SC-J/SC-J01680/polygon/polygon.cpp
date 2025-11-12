#include <bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
int n,a[maxn],dp[maxn][maxn];
long long ans;
int tsxz(int n,int k){
	if(n==k)return 1;
	if(k==1||k==0)return dp[n][k]=n;
	if(dp[n][k]!=0)return dp[n][k];
	int temp=tsxz(n-1,k-1)+tsxz(n-1,k);
	if(temp>mod)temp-=mod;
	//cout<<n<<" "<<k<<" "<<temp<<"\n";
	return dp[n][k]=temp;
}
void dfs(int start,int total,int k,int ma){
	if(total>ma*2&&k>=3){
		ans++;
		if(ans>mod)ans-=mod;
	}
	if(start>n)return;
	for(int i=start;i<n;i++){
		int temp=max(a[i],ma);
		dfs(i+1,total+a[i],k+1,temp);	
	}
}
void read(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool p=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)p=0;
	}
	if(p){//最大为1；
		for(int i=3;i<n;i++){
			if(n-i<i)dp[n][i]=tsxz(n,n-i);//试图加速
			else tsxz(n,i);
			ans+=dp[n][i];
//			cout<<dp[n][i]<<" ";
			if(ans>mod)ans-=mod;
		}
		cout<<(ans+1)%mod<<"\n";
	}else{
		dfs(0,0,0,0);
		cout<<ans%mod<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	read();
	
	return 0;
}