#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],dp[110][110][110],fa=1,fb=1;
vector<int>c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]||a[i][2])fa=0;
		}
		if(fa){
			for(int i=1;i<=n;i++)c.push_back(a[i][0]);
			sort(c.begin(),c.end());
			reverse(c.begin(),e.end());
			int ans=0;
			for(int i=0;i<min(n/2,c.size());i++)ans+=c[i];
			cout<<ans;
			return 0;
		}
		if(n<=200){
			int ans=0;
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int x=0;x<=min(n/2,i);x++)for(int y=0;y<=min(n/2,i-x);y++){
					int z=i-x-y;
					if(z>n/2)continue;
					dp[x][y][z]=0;
					if(x)dp[x][y][z]=max(dp[x][y][z],dp[x-1][y][z]+a[i][0]);
					if(y)dp[x][y][z]=max(dp[x][y][z],dp[x][y-1][z]+a[i][1]);
					if(z)dp[x][y][z]=max(dp[x][y][z],dp[x][y][z-1]+a[i][2]);
					if(i==n)ans=max(ans,dp[x][y][z]);
				}
			}
			cout<<ans<<'\n';
		}
	}
} 
