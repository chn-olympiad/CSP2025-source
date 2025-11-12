#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int t,n,a[100005],b[100005],c[100005];
map<int,map<int,map<int,int> > >dp;
void solve(){
	dp.clear();
	cin>>n;
	int f3=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i]) f3=1;
		if(b[i]) f2=1;
	}
	if(!f3&&!f2){
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=n/2+1;i<=n;i++) sum+=a[i];
		cout<<sum<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int x=min(i,n/2);x>=0;x--){
			for(int y=min(i-x,n/2);y>=0;y--){
				int z=i-x-y;
				if(z>n/2) continue;
				dp[x][y][z]=max(dp[x][y][z],max((x?dp[x-1][y][z]+a[i]:0),max((y?dp[x][y-1][z]+b[i]:0),(z?dp[x][y][z-1]+c[i]:0))));
//				if(x==2&&y==2&&z==0) cout<<dp[x][y][z]<<" ";
//				cout<<x<<";"<<y<<";"<<z<<";"<<dp[x][y][z]<<endl;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			int k=n-i-j;
			if(k>n/2) continue;
			ans=max(ans,dp[i][j][k]);
//			cout<<i<<";"<<j<<";"<<k<<";"<<dp[i][j][k]<<" ";
		}
//		cout<<endl;
	}
	cout<<ans/*<<" "<<dp[2][2][0]*/<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
