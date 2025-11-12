#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][5];
int t,n,ans;
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(x+1,sum+a[x+1][1],cnt1+1,cnt2,cnt3);
	if(cnt2<n/2) dfs(x+1,sum+a[x+1][2],cnt1,cnt2+1,cnt3);
	if(cnt3<n/2) dfs(x+1,sum+a[x+1][3],cnt1,cnt2,cnt3+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		dfs(1,a[1][1],1,0,0);
		dfs(1,a[1][2],0,1,0);
		dfs(1,a[1][3],0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
