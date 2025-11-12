#include<bits/stdc++.h>
#define int int64_t
using namespace std;
struct node{
	int x,y,z;
}a[int(1e5+5)];
int v,n;
int ans;
void dfs(int id,int x,int y,int z,int sum){
	if(x>v||y>v||z>v)return;
	ans=max(ans,sum);
	if(id>n)return;
	dfs(id+1,x+1,y,z,sum+a[id].x);
	dfs(id+1,x,y+1,z,sum+a[id].y);
	dfs(id+1,x,y,z+1,sum+a[id].z);
}
int32_t main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		v=(n>>1);
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
