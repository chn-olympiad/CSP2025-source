#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005][4],ans,mx;
void dfs(ll x,ll num,ll c1,ll c2,ll c3){
	if(c1>mx||c2>mx||c3>mx) return;
	if(x==n+1){
		ans=max(num,ans);
		return;
	}
	
	dfs(x+1,num+a[x][1],c1+1,c2,c3);
	dfs(x+1,num+a[x][2],c1,c2+1,c3);
	dfs(x+1,num+a[x][3],c1,c2,c3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
