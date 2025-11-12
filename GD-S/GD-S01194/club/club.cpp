#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
ll n,t,ans;
struct q{
	int x,y,z;
	int dx;
}a[N];
void dfs(int t,ll sum,int nx,int ny,int nz){
	if(t==n+1){
		ans=max(ans,sum);
		return;
	}
	if(nx<(n/2)) dfs(t+1,sum+a[t].x,nx+1,ny,nz);
	if(ny<(n/2)) dfs(t+1,sum+a[t].y,nx,ny+1,nz);
	if(nz<(n/2)) dfs(t+1,sum+a[t].z,nx,ny,nz+1);
	return;
}
bool cmpp(q x,q y){
	return x.dx<y.dx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		int maxxx=-1;
		for(int i=1;i<=n;i++){
			a[i].dx=a[i].y-a[i].x;
			maxxx=max(maxxx,a[i].z);
		}
		if(maxxx==0){
			sort(a+1,a+1+n,cmpp);
			ll summ=0;
			for(int i=1;i<=(n/2);i++) summ+=a[i].x;
			for(int i=(n/2)+1;i<=n;i++) summ+=a[i].y;
			cout<<summ<<endl;
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
