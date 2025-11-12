#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=210;
int ans,t,n,vis[N],a[5][N*1000],x,cnt,dp[N/2][N/2][N/2],lst[N/2][N/2][N/2];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;int f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
			}
			if(a[3][i]!=0)f=1;
		}
		if(n<=200){
			memset(dp,0,sizeof(dp));
			memset(lst,0,sizeof(lst));
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++)
					for(int z=0;z<=n/2;z++)
						for(int w=0;w<=n/2;w++){
							if(j+z+w>n)continue;
							if(j>0)dp[j][z][w]=max(dp[j][z][w],lst[j-1][z][w]+a[1][i]);
							if(z>0)dp[j][z][w]=max(dp[j][z][w],lst[j][z-1][w]+a[2][i]);
							if(w>0)dp[j][z][w]=max(dp[j][z][w],lst[j][z][w-1]+a[3][i]);
						}
				for(int j=0;j<=n/2;j++)
					for(int z=0;z<=n/2;z++)
						for(int w=0;w<=n/2;w++){
							if(j+z+w>n)continue;
							lst[j][z][w]=dp[j][z][w];
						}
			}
			for(int j=0;j<=n/2;j++){
				for(int z=0;z<=n/2;z++){
					for(int w=0;w<=n/2;w++){
						if(j+z+w>n)continue;
						ans=max(ans,dp[j][z][w]);
					}
				}
			}
			cout<<ans<<"\n";
		}
		else if(f==1){
			for(int i=1;i<=n;i++){
				ans+=max(a[1][i],max(a[2][i],a[3][i]));
			}
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=3;i++)sort(a[i]+1,a[i]+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans+a[1][i]+a[2][i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

