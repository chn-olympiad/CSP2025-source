#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int t,n;
long long a[MAX][4],ans;
void dfs(int k,int x,int y,int z,long long sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2) dfs(k+1,x+1,y,z,sum+a[k][1]);
	if(y<n/2) dfs(k+1,x,y+1,z,sum+a[k][2]);
	if(z<n/2) dfs(k+1,x,y,z+1,sum+a[k][3]);
}
void judge(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++) judge();
	return 0;
}
