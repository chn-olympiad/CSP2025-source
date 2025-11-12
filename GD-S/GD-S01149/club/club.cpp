#include<bits\stdc++.h>
using namespace std;
const int N=1e5+3;
int t,n;
long long dp[N][3];int pp[N][3][3],a[3][N],aaa[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;int maxp=n>>1;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(pp,0,sizeof(pp));
		int cnt;bool flag=1;
		for(int i=1;i<=n;++i){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(a[1][i]==0&&a[2][i]==0){
				cnt++;
				if(cnt>=114)flag=0;
			}
		}
		if(!flag){
			long long ans;
			for(int i=1;i<=n;++i){
				aaa[i]=a[0][i];
			}
			sort(aaa+1,aaa+n+1,cmp);
			for(int i=1;i<=maxp;++i){
				ans+=aaa[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<3;++i){
			dp[1][i]=a[i][1];
			pp[1][i][i]=1;
		}
		for(int i=2;i<=n;++i){
			for(int j=0;j<3;++j){
				long long maxdp=-1;int now[3]={0,0,0};
				for(int k=0;k<3;k++){
					if(maxp>pp[i-1][j][k]){
						maxdp=max(maxdp,dp[i-1][j]+a[k][i]);
						if(maxdp==dp[i-1][j]+a[k][i]){
							for(int w=0;w<3;w++){
								now[w]=pp[i-1][j][w];
								if(w==k)now[w]++;
							}
						}
					}
				}
				dp[i][j]=maxdp;
				for(int ww=0;ww<3;ww++){
					pp[i][j][ww]=now[ww];
				}
			}
		}
		long long ans=max(dp[n][0],dp[n][1]);
		cout<<max(ans,dp[n][2])<<endl;
	}
	return 0;
}
