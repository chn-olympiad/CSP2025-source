#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int  x,y,z; 
}a[100001];
int ans=0,n,t;
void dfs(int nx,int ny,int nz,int sum,int now){
	if(now>n){
		ans=max(ans,sum);
		return ;
	}
	if(nx<n/2)dfs(nx+1,ny,nz,sum+a[now].x,now+1);
	if(ny<n/2)dfs(nx,ny+1,nz,sum+a[now].y,now+1);
	if(nz<n/2)dfs(nx,ny,nz+1,sum+a[now].z,now+1);
}
bool cmp(node x,node y){
	return x.x>y.x;
}
void solve(){
	cin>>n;
	if(n<=30){
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
		return ;
	}
	else{
		int flagy=0,flagz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y)flagy=1;
			if(a[i].z)flagz=1;
		}
		if(!flagy&&!flagz){
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			return ;
		}
	}
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve(); 
	}
}//初二还没AK j组，s组还没一等
//S 45 J 300，机房一群AK J的 
//成为机房初二退役第一人 
