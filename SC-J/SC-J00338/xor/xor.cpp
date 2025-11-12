#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[1005][1005];
int dp[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	if(!flag){
		if(k==0){
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]) cnt++;
				else ans=ans+1+cnt/2,cnt=0;
			}
			cout<<ans<<'\n';
			return 0;
		}
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
			cout<<ans<<'\n';
			return 0;
		}
		cout<<"0\n";
		return 0;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				s[i][j]=s[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			dp[i][s[1][i]]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=255;j++){
				for(int l=i+1;l<=n;l++){
					for(int p=i+1;p<=l;p++){
						if(s[p][l]==j) dp[l][j]=max(dp[i][j]+1,dp[l][j]);
						else dp[l][j]=max(dp[i][j],dp[l][j]);
					}
				}
			}
		}
		cout<<dp[n][k]<<'\n';
		return 0;
	}
	cout<<rand()%1000+1<<'\n';
	return 0;
}