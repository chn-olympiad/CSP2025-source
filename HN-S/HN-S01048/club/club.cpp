#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],ans;
void dfs(int d,int k1,int k2,int k3,int s){
	if(k1>n/2||k2>n/2||k3>n/2||d>n+1)return;
	ans=max(s,ans);
	dfs(d+1,k1+1,k2,k3,s+a[d][1]);
	dfs(d+1,k1,k2+1,k3,s+a[d][2]);
	dfs(d+1,k1,k2,k3+1,s+a[d][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	} 
	return 0;
}
