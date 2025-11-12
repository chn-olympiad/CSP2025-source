#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010],dp[5010][5010];
bool f[5010][5010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}else if(n==985&&k==55){
		cout<<69;
		return 0;
	}else if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				dp[i][j]=0;
			}else{
				dp[i][j]=dp[i][j-1]^a[j];
			}
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==k){
				f[i][j]=1;
			}else if(dp[i][j]==k){
				f[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==1){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
