#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][10];
int dp[N];
int b[10];
int as[10];
int ans;
int vis[N];
void dfs(int k){
	if(b[1]>n/2||b[2]>n/2||b[3]>n/2){
		return;
	}
	if(k==n+1){
		ans=max(ans,as[1]+as[2]+as[3]);
		return;
	}
	int res=0;
	for(int i=1;i<=3;i++){
		as[i]+=a[k][i];
		b[i]++;
		dfs(k+1);
		b[i]--;
		as[i]-=a[k][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++){
			b[i]=0;
			as[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
} 
