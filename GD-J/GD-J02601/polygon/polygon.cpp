#include<bits/stdc++.h>
using namespace std;
int a[5010];
int dp[110][50010];
int tmp[110][50010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mx=0;
	int sum=0; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=mx;j++){
			for(int k=0;k<=sum-a[i];k++){
				tmp[max(a[i],j)][k+a[i]]+=dp[j][k];
				tmp[max(a[i],j)][k+a[i]]%=998244353;
			}
		}
		for(int j=0;j<=mx;j++){
			for(int k=0;k<=sum;k++){
				tmp[j][k]+=dp[j][k];
				tmp[j][k]%=998244353;
				dp[j][k]=tmp[j][k];
			}
		}
		memset(tmp,0,sizeof(tmp));
	}
	int res=0;
	for(int i=0;i<=mx;i++){
		for(int j=i*2+1;j<=sum;j++){
			res+=dp[i][j];
			res%=998244353;
		}
	}
	cout<<res;
	return 0;
} 
