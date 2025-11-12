//GZ-S00051 北师大附中 刘子逍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int t,n;
ll a[100010][4],f[4][100010],cnt[4],ans;
void dfs(int p,int l){
	for(int i=1;i<=3;++i){
		if(cnt[i]+1<=n/2 && f[l][p-1]+a[p][i]>=f[i][p] && p<=n){
			int t=f[i][p];
			f[i][p]=f[l][p-1]+a[p][i];
			//cout<<p<<','<<i<<','<<l<<':'<<f[i][p]<<','<<a[p][i]<<'\n';
			ans=max(ans,f[i][p]);
			++cnt[i];
			dfs(p+1,i);
			--cnt[i];
			f[i][p]=t;
		} 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		//int fg=0;
		for(int i=1;i<=n;++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
		
		//if(a[i][1]==0 || a[i][2]==0 || a[i][3]==0) fg=1;
		ans=0;
		//f[1][1]=a[1][1],f[2][1]=a[2][1],f[3][1]=a[2][1];
		//for(int i=1;i<=3;++i) cnt[i]=0;
		dfs(1,1);
		/*
		for(int i=1;i<=3;++i){
			for(int j=1;j<=n;++j) cout<<f[i][j]<<' ';
			cout<<'\n';
		}
		
		//f[1][0]=a[1][1],f[2][0]=a[1][2],f[3][0]=a[1][3];
		ans=0;
		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				for(int k=0;k<min(n/2,i);++k){
					for(int k1=0;k1<=k;++k1){
						if(j!=1 || k!=k1) dp[j][k]=max(dp[j][k],f[1][k1]+a[i][j]);
						if(j!=2 || k!=k1) dp[j][k]=max(dp[j][k],f[2][k1]+a[i][j]);
						if(j!=3 || k!=k1) dp[j][k]=max(dp[j][k],f[3][k1]+a[i][j]);
						/*
						if(j==1 && k==k1) dp[j][k]=max(dp[j][k],f[1][k]-a[i-2][1]+max(a[i-2][2],a[i-2][3])+a[i][j]);
						if(j==2 && k==k1) dp[j][k]=max(dp[j][k],f[1][k]-a[i-2][2]+max(a[i-2][1],a[i-2][3])+a[i][j]);
						if(j==3 && k==k1) dp[j][k]=max(dp[j][k],f[1][k]-a[i-2][3]+max(a[i-2][1],a[i-2][2])+a[i][j]);
						
						ans=max(ans,dp[j][k]);
					}
				}
			}
			
			cout<<'\n';
			for(int j=1;j<=3;++j) for(int k=0;k<max(n/2,i);++k) f[j][k]=dp[j][k],dp[j][k]=0;
			for(int k=0;k<min(n/2,i);++k){
				for(int j=1;j<=3;++j) cout<<f[j][k]<<' ';
				cout<<'\n';
			}
		}*/
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/	

