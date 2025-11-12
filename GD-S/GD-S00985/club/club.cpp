#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int N=201;
ll n,dp[N][N][N];
struct node{
	ll f,s,t; 
}a[100005];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n>100000){
			for(int i=1;i<=n;i++){
				cin>>a[i].f>>a[i].s>>a[i].t;	
			}
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].f;
			}
			cout<<ans;
			continue;
		}
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int l=n/2;l>=0;l--){
						int z=dp[j-1][k][l]+a[i].f,w=dp[j][k-1][l]+a[i].s,y=dp[j][k][l-1]+a[i].t;
						if(j)dp[j][k][l]=max(dp[j][k][l],z);
						if(k)dp[j][k][l]=max(dp[j][k][l],w);
						if(l)dp[j][k][l]=max(dp[j][k][l],y);
					}
				}
			}
		}
		ll ans=0;
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				for(int l=n/2;l>=0;l--){
					ans=max(ans,dp[j][k][l]);
				} 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
