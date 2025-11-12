#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100005],ans;
void dfs(int n1,int n2,int n3,int s,int c){
	if(c>n){
		ans=max(ans,s);
		return;
	}
	if(n1+1<=n/2)dfs(n1+1,n2,n3,s+a[1][c],c+1);
	if(n2+1<=n/2)dfs(n1,n2+1,n3,s+a[2][c],c+1);
	if(n3+1<=n/2)dfs(n1,n2,n3+1,s+a[3][c],c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i];
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}
