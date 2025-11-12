#include<bits/stdc++.h>
#define int long long
using namespace std;
//int dp[200005][3];
int t,n,a[100005][4],e[4],k[4],ans,p[100005],x;
bool f[100005];
void dfs(int dep){
	if(dep==n+1){
		ans=max(ans,e[1]+e[2]+e[3]);
	}
	if(k[1]<n/2){
		k[1]++;
		e[1]+=a[dep][1];
		dfs(dep+1);
		k[1]--;
		e[1]-=a[dep][1];
	}
	if(k[2]<n/2){
		k[2]++;
		e[2]+=a[dep][2];
		dfs(dep+1);
		k[2]--;
		e[2]-=a[dep][2];
	}
	if(k[3]<n/2){
		k[3]++;
		e[3]+=a[dep][3];
		dfs(dep+1);
		k[3]--;
		e[3]-=a[dep][3];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
//		e.clear();
		memset(f,0,sizeof f);
		memset(k,0,sizeof k);
		memset(e,0,sizeof e);
		if(n>=100000){
			for(int i=1;i<=n;i++){
				cin>>p[i]>>x>>x;
				}
			sort(p+1,p+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=p[i];
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++)cin>>a[i][j];
				}
			dfs(1);
			cout<<ans<<'\n';
		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				dp[j]
//			}
//		}
		
	}
	return 0;
}

