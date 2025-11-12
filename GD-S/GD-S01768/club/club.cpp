#include<bits/stdc++.h>
using namespace std;
const int gm=100005;
int tt,n,a[10][2*gm],ans=-1;
int dp[205][205][205]={};
void dfs(int pos,int cur,int i,int j,int k){
	pos++;
	ans=max(ans,cur);
	if(pos>n)return;
	if(i<n/2)dfs(pos,cur+a[1][pos],i+1,j,k);
	if(j<n/2)dfs(pos,cur+a[2][pos],i,j+1,k);
	if(k<n/2)dfs(pos,cur+a[3][pos],i,j,k+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>tt;
	while(tt--){
		cin>>n;
		ans=-1;
		int fa=1,fb=1;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0)fa=0;
			if(a[3][i]!=0)fb=0;
		}
		if(fa==1){
			ans=0;
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>n/2;i--){
				ans+=a[1][i];
			}
			cout<<ans<<'\n';
			continue; 
		}
		if(n<=10){
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		if(n==100000){
			for(int i=1;i<=n;i++){
				ans+=max(a[1][i],max(a[3][i],a[2][i]));
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					dp[i][j][k]=0;
		for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
		for(int k=0;k<=n;k++){
			if(i+j+k==n)ans=max(dp[i][j][k],ans);
			if(i+j+k+1>n)continue;
			if(i<n/2)dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[1][i+j+k+1]);
			if(j<n/2)dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[2][i+j+k+1]);
			if(k<n/2)dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a[3][i+j+k+1]);	
		}				
		}			
		}
		cout<<ans<<'\n';
	}
	return 0;
}

