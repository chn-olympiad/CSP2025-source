#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5050],ans;
//int dp[5050][5050];
bool vis[5050][5050],c[5050][5050];
bool cmp(int x,int y){
	return x>y;
}
void DFS(int l,int r,int sum){
	vis[l][r]=1;
	if(r-l<=2&&r==n){
		return;
	}
	if(vis[l][r+1]==0&&r<n){
		if(c[l][r]=1){
			c[l][r+1]=1;
		}
		else{
			if(a[r+1]+sum>=2*a[l]){
				c[l][r+1]=1;
				ans++;
			}
			else{
				c[l][r+1]=0;			
			}
		}
		DFS(l,r+1,sum+a[r+1]);
	}
	if(vis[l+1][r]==0&&l<r){
		if(sum-a[l]>=2*a[l-1]&&r-l>=2){
			c[l+1][r]=1;
		}
		else{
			c[l+1][r]=0;			
		}
		DFS(l+1,r,sum-a[l]);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	int s=a[1]+a[2]+a[3];
	if(s>=2*a[1]){
		c[1][3]=1;
		ans++;
	}
	DFS(1,3,s);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<c[i][j]<<" ";
			if(c[i][j]==1){
				ans++;
			}
		}
		//cout<<endl;
	}
	cout<<endl;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans%mod;
	return 0;
}
