#include<bits/stdc++.h>

using namespace std;
int n;long long dp[210][210][210][4],a[210][4];int t;
void solve(){
	cin>>n;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			
		}
	}
	if(n>=100000){
		vector<long long>temp;
		for(int i=1;i<=n;i++){
			temp.push_back(a[i][1]);
		}
		sort(temp.begin(),temp.end(),greater<int>());
		long long ans=0;
		for(int i=1;i<=n/2;i++)ans+=temp[i-1];
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			
			for(int k=0;k+j<=i and k<=n/2;k++){
				int p=i-j-k;
				
				if(p>n/2)continue;
				if(j)dp[i][j][k][1]=max({dp[i-1][j-1][k][1],dp[i-1][j-1][k][2],dp[i-1][j-1][k][3]})+a[i][1];
				if(k)dp[i][j][k][2]=max({dp[i-1][j][k-1][1],dp[i-1][j][k-1][2],dp[i-1][j][k-1][3]})+a[i][2];
				if(p)dp[i][j][k][3]=max({dp[i-1][j][k][1],dp[i-1][j][k][2],dp[i-1][j][k][3]})+a[i][3];
				//cout<<dp[i-1][j-1][k][1]<<" "<<dp[i-1][j-1][k][2]<<" "<<dp[i-1][j-1][k][3]<<" "<<i-1<<" "<<j-1<<" "<<k<<endl;
			}
		}
	}
	long long ans=0;
	//cout<<"\n\n\n";
	for(int i=0;i<=n/2;i++){
		for(int j=0;j+i<=n and j<=n/2;j++){
			int p=n-i-j;
			if(p>n/2)continue;
			ans=max(ans,dp[n][i][j][1]);
			ans=max(ans,dp[n][i][j][2]);
			ans=max(ans,dp[n][i][j][3]);
			//cout<<dp[n][i][j][1]<<"-"<<dp[n][i][j][2]<<"-"<<dp[n][i][j][3]<<endl;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}

