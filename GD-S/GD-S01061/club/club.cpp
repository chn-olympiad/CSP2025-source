#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct node{
	int a,b,c;
}a[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag2=1,flag3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			flag2&=(a[i].b==0);
			flag3&=(a[i].c==0);
		}
		if(flag2&&flag3){
			ll ans=0;
			priority_queue<int> q;
			for(int i=1;i<=n;i++){
				q.push(a[i].a);
			}
			while((int)q.size()>n/2){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<"\n";
		}else if(flag3){
			ll dp[2][n/2+10];
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int x=0;x<=min(i,n/2);x++){
					if(x>=1) dp[i&1][x]=max(dp[i&1][x],dp[(i-1)&1][x-1]+a[i].a);
					if(i-x>=1) dp[i&1][x]=max(dp[i&1][x],dp[(i-1)&1][x]+a[i].b);
				}
			}
			ll ans=0;
			for(int x=0;x<=n/2;x++){
				ans=max(ans,dp[n&1][x]);
			}
			cout<<ans<<"\n";
		}else{
			ll dp[2][n/2+10][n/2+10];
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int x=0;x<=min(i,n/2);x++){
					for(int y=0;x+y<=i&&y<=min(i,n/2);y++){
						if(i-x-y>n/2) continue;
						if(x>=1) dp[i&1][x][y]=max(dp[i&1][x][y],dp[(i-1)&1][x-1][y]+a[i].a);
						if(y>=1) dp[i&1][x][y]=max(dp[i&1][x][y],dp[(i-1)&1][x][y-1]+a[i].b);
						if(i-x-y>=1) dp[i&1][x][y]=max(dp[i&1][x][y],dp[(i-1)&1][x][y]+a[i].c);
					}
				}
			}
			ll ans=0;
			for(int x=0;x<=n/2;x++){
				for(int y=0;y<=n/2;y++){
					ans=max(ans,dp[n&1][x][y]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
