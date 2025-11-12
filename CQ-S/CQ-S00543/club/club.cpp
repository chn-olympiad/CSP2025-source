#include<bits/stdc++.h>
using namespace std;//40
int T,n,ans,len;
struct node{
	int x,y,z,h;
}a[100005];
void dfs(int kx,int ky,int kz,int sum,int s){
	if(s==n+1){
		ans=max(ans,sum);
		return;
	}
	if(kx<len)dfs(kx+1,ky,kz,sum+a[s].x,s+1);
	if(ky<len)dfs(kx,ky+1,kz,sum+a[s].y,s+1);
	if(kz<len)dfs(kx,ky,kz+1,sum+a[s].z,s+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int x1=0,y1=0,z1=0,mx;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		len=n/2;
		ans=-1e9;
		dfs(0,0,0,0,1);
		cout<<ans<<endl; 
	}	
	return 0;
} 
