#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e3+5;
#define int long long
int n,k,a[N],bj[25],sum[M][M][25],w[M][25],dp[M];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];	
	if(n<=100&&k==0) {
		int cnt=0;
		for(int i=1;i<=n;i++) if(a[i]==0||(a[i]==a[i-1])) cnt++;
		cout<<cnt;
		return 0;
	}	
	if(n<=100&&k==1){
		int cnt=0;			
		for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
		cout<<cnt;
		return 0;			
	}
	int x=0;
	while(k){
		int u=k&1;
		if(u) bj[x]=1;
		k>>=1;
		x++;
	}	
	for(int i=1;i<=n;i++){
		x=0;
		while(a[i]){
			if(a[i]&1) w[i][x]=1;
			x++;
			a[i]>>=1;
		}	
	}
	for(x=1;x<=20;x++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j!=i) sum[i][j][x]=sum[i][j-1][x]+w[j-1][x];
				sum[i][j][x]=w[j-1][x];
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			bool flag=1;
			for(x=1;x<=20;x++){
				if(sum[i][j][x]%2==0&&bj[x]==1){
					flag=0; break;
				} 
				if(sum[i][j][x]%2==1&&bj[x]==0){
					flag=0; break;
				} 								
			}
			if(flag) dp[j]=max(dp[j],dp[i-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
















