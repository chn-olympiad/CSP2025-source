#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001][3];
int vis[3]={0,0,0},maxa;
int sum1=0;
int ans=0;
void dfs(int step){
	if(step==n){
		ans=max(ans,sum1); 
		return;
	}
	for(int i=0;i<3;i++){
		if(vis[i]<=maxa){
			sum1+=a[step][i];
			vis[i]++;
			dfs(step+1);
			sum1-=a[step][i];
			vis[i]--;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int u;
	cin>>u;
	for(int h=0;h<u;h++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		} 
		maxa=n/2;
		dfs(0);
		cout<<ans<<endl;
		sum1=0;
		ans=0;
		vis[0]=0;
		vis[1]=0;
		vis[2]=0;
	}
	return 0;
} 
