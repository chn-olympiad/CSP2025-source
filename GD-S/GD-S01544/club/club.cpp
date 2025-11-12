#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005][4];
int ans=-1;
void dfs(int x,int sum,int ca,int cb,int cc){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(ca<n/2)dfs(x+1,sum+a[x][1],ca+1,cb,cc);
	if(cb<n/2)dfs(x+1,sum+a[x][2],ca,cb+1,cc);
	if(cc<n/2)dfs(x+1,sum+a[x][3],ca,cb,cc+1);
}
void fun(){
	ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		fun();
	}
	return 0;
}
