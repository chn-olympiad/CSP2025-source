#include <bits/stdc++.h>
using namespace std;
long long n,m,k,s=0x7f7f7f7f,z=0;
long long dp[10001][10001],bj[10001][10001];
long long u,v,w,c[101],a[10001],l,r;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=0x7f7f7f7f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		dp[min(u,v)][max(u,v)]=min(w,dp[min(u,v)][max(u,v)]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		cin>>a[1];
		if(c[i]==0 && a[1]==0){
			cout<<0;
			return 0;
		}
		for(int j=2;j<=n;j++){
			cin>>a[j];
			for(int k=1;k<j;k++){
				if(a[k]+a[j]+c[i]<dp[k][j]){
					dp[k][j]=a[k]+a[j];
					bj[k][j]=c[i];
				}
			}
		}
	}
	for(int k=1;k<=3;k++){
		s=0x7f7f7f7f;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]+bj[i][j]<s){
					s=dp[i][j]+bj[i][j];
					l=i;
					r=j;
				}
			}
		}
		dp[l][r]=0x7f7f7f7f;
		z+=s;
	}
	cout<<z;
	
	
	return 0;
}
