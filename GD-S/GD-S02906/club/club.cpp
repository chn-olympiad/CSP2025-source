#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t;
int n,ans;
struct node{
	int x,y,z,sum;
}a[N];
void dfs(int sum,int u,int v,int w,int k){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(u<n/2) dfs(sum+a[k].x,u+1,v,w,k+1); 
	if(v<n/2) dfs(sum+a[k].y,u,v+1,w,k+1); 
	if(w<n/2) dfs(sum+a[k].z,u,v,w+1,k+1); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		ans=0;
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}

