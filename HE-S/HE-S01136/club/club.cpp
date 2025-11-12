#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10010;
int t;
int a[N][5];
int dp[N][N/2];
int v[N];
int cnt[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof v);
		memset(dp,0,sizeof dp);
		memset(cnt,0,sizeof cnt);
		memset(a,0,sizeof a);
		int n;
		cin>>n;
		int shu=n/2; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		bool fg=false;
		for(int i=1;i<=n;i++) {
			for(int j=2;j<=3;j++){
				if(a[i][j]!=0) fg=true;
			}
		}
		if(fg==false){
			int dzd[n];
			for(int i=1;i<=n;i++)
				dzd[i]=a[i][1];
			sort(dzd+1,dzd+1+n);
			int www=0;
			for(int i=1;i<=(n/2);i++){
				www+=dzd[i];
			}
			cout<<www<<endl;
			continue;
		}
		for(int i=1;i<=3;i++) dp[i][0]=0;
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i]+1<=shu){
					if(dp[i][cnt[i]]<=dp[i][cnt[i]+1]+a[j][i]){
						if(v[j]==0){
							cnt[i]++;
							v[j]=i;
							ans+=a[j][i];
							dp[i][cnt[i]]=dp[i][cnt[i]-1]+a[j][i];
						}
						else{
							if(a[j][v[j]]<a[j][i]){
								ans-=a[j][v[j]];
								int xian=v[j];
								v[j]=i;
								cnt[i]++;
								cnt[v[j]]--;
								dp[xian][cnt[v[j]]]=dp[xian][cnt[v[j]]+1]-a[j][xian];
								dp[i][cnt[i]]=dp[i][cnt[i]-1]+a[j][i];
								ans+=a[j][v[j]];
							}
						}
					}
					else continue;
				}
				else{
					break;
				}
			}
		}
	cout<<ans<<endl;
}
	return 0;
}
