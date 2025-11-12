#include<bits/stdc++.h>

using namespace std;

#define int long long

int b[100005];
int dp[10005][2]={0};
int ans=0;

signed main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	
	sort(b,b+n);
	
	for(int i=0;i<n;i++){
		for(int j=b[i]*2+1;j<=10002+b[i];j++){
			int read=j-b[i];
			if(read<0)continue;
			if(read==0){
				ans+=1;
				ans%=998244353;
				continue;
			}
			ans+=dp[read][1];
			ans%=998244353;
		}
		for(int j=10002;j>=0;j--){
			int nxt=j+b[i];
			if(nxt>=10002)nxt=10002;
			dp[nxt][1]+=dp[j][0]+dp[j][1];
			dp[nxt][1]%=998244353;
		}	
		dp[b[i]][0]++;	
	}
	
	cout<<ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

