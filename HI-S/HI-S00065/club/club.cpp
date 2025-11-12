#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int dp[100005],num[100005][3];
	int vis[100005],numa[3],numb[100005];
	int n,t;
	cin>>t;
	while(t--){
		memset(numa,0,sizeof(numa));
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[i][0]>>num[i][1]>>num[i][2];
		}
		for(int i=1;i<=n;i++){
			int maxi=0;
			for(int j=1;j<3;j++){
				if(num[i][j]>num[i][maxi]){
					maxi=j;
				}
			}
			dp[i]=num[i][maxi];
			numa[maxi]++;
		}
		for(int i=1,max1,max2;i<=n;i++){
			max1=0,max2=0;
			for(int j=1;j<3;j++){
				if(num[i][j]>num[i][max1]){
					max1=j;
				}
			}
			if(max1==0){
				max2=1;
			}
			for(int j=1;j<3;j++){
				if(num[i][j]>num[i][max2] && j!=max1){
					max2=j;
				}
			}
			numb[i]=num[i][max1]-num[i][max2];
		}
		for(int i=0;i<3;i++){
			if(numa[i]>=n/2){
			for(int j=0;j<numa[i]-n/2;j++){
				int mini=1;
				for(int k=2;k<=n;k++){
					if(numb[mini]>numb[k] && vis[k]==0){
						mini=k;
					}
				}
				dp[mini]-=numb[mini];
				vis[mini]=1;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=dp[i];
			cout<<dp[i]<<' ';
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
