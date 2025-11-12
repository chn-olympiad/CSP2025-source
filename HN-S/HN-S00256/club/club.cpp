#include<bits/stdc++.h>

using namespace std;

int t,n,a[100010],b[100010],c[100010],dis[100010],ans=0;
void dfs(int sum,int id,int x,int y,int z){
	if(sum+dis[id]<ans&&id<=n) return ;
	if(id>n){
		ans=max(ans,sum);
		return ;
	}
	if(x<n/2) dfs(sum+a[id],id+1,x+1,y,z);
	if(y<n/2) dfs(sum+b[id],id+1,x,y+1,z);
	if(z<n/2) dfs(sum+c[id],id+1,x,y,z+1);
}

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];	
		}
		for(int i=n;i>=1;i--) dis[i]=dis[i+1]+max({a[i],b[i],c[i]});
		ans=-1;
		dfs(0,1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
