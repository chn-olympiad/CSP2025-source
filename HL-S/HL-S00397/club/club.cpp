#include<bits/stdc++.h>
using namespace std;
int n,sum,a[100005][5]={0};
void dfs(int dep,int s,int b1,int b2,int b3){
	if(dep==n+1){
		sum=max(sum,s);
		return;
	}
	if(b1<n/2)dfs(dep+1,s+a[dep][1],b1+1,b2,b3);
	if(b2<n/2)dfs(dep+1,s+a[dep][2],b1,b2+1,b3);
	if(b3<n/2)dfs(dep+1,s+a[dep][3],b1,b2,b3+1);
}
void solve(){
	memset(a,0,sizeof(a));
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	dfs(1,0,0,0,0);
	cout<<sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
