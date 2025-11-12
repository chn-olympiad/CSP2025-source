#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int dp[500005];
int maxn=0;

void fun(){
	maxn=0;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int s=a[i];
		int j;
		
		if(dp[i]==-1){
			dp[i]=maxn;
		}
		
		for(j=i;j<=n;j++){
			if(s==k){
				dp[j]=maxn+1;
				break;
			}
			s=s^a[j+1];
		}
		maxn=max(maxn,dp[i]);
		//~ cout<<maxn<<"\n";
	}
	//~ for(int i=1;i<=n;i++)
		//~ cout<<dp[i]<<" ";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=-1;
	}
	fun();
	cout<<maxn;
	
	return 0;
}
