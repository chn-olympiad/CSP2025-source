#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],dp[305][305][305],ans;
vector<pair<int,int>>f[4];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first>b.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n<=200){
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int l=n/2;l>=0;l--){
						if(j!=0){
							dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
						}
						if(k!=0){
							dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
						}
						if(l!=0){
							dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
						}
					}
				}
			}
		}
		cout<<dp[n/2][n/2][n/2]<<'\n';
	}
		else{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(j==1){
						sum+=a[i][j];
						continue;
					}
					if(a[i][j]==0)cnt++;
				}
			}
			if(cnt==2*n){
				cout<<sum<<'\n';
				continue;
			}
			else{
				for(int i=1;i<=n;i++){
					int mx=0,id=0;
					for(int j=1;j<=2;j++){
						if(a[i][j]>=mx){
							mx=a[i][j],id=j;
						}
					}
					f[id].push_back(make_pair(mx,i));
				}
				int cnt=0,ans=0;
				sort(f[1].begin(),f[1].end(),cmp);
				for(int i=0;i<f[1].size();i++){
					if(++cnt<=n/2)ans+=f[1][i].first;
					else ans+=a[f[1][i].second][2];
				}cnt=0;for(int i=0;i<f[2].size();i++){
					if(++cnt<=n/2)ans+=f[2][i].first;
					else ans+=a[f[2][i].second][1];
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
