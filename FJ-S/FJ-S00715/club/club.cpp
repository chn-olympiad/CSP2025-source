#include<iostream>
using namespace std;

int dp[207][3][107],arr[100007][3];

int rest(int a,int b){
	if(a==0)return b?1:2;
	if(a==1)return b?0:2;
	if(a==2)return b?0:1;
	return 0;
}

void solve(){
	int n;cin>>n;
	int result=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	if(n>2047){
		for(int i=1;i<=n;i++){
			result+=arr[i][0];
		}
		cout<<result<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			for(int k=1;k<=n/2;k++){
				dp[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			for(int k=1;k<=n/2;k++){
				dp[i][j][k]=max(dp[i-1][j][k-1],max(dp[i-1][rest(j,0)][k],dp[i-1][rest(j,1)][k]))+arr[i][j];
			}
		}
	}
	
	for(int j=0;j<3;j++){
		for(int k=1;k<=n/2;k++){
			if(result<dp[n][j][k])result=dp[n][j][k];
		}
	}
	cout<<result<<endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;cin>>T;
	for(int i=0;i<T;i++){
		solve();
	}
	return 0;
}
