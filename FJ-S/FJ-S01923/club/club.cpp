#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[5][100005],maxx;
void dfs(ll x,ll xx,ll y,ll yy,ll z,ll zz,ll j){
	if(j>n){
		maxx=max(maxx,x+y+z);
		return;
	}
	for(ll i=j;i<=n;i++){
		if(xx<n/2)
			dfs(x+a[1][i],xx+1,y,yy,z,zz,i+1);
		if(yy<n/2)
			dfs(x,xx,y+a[2][i],yy+1,z,zz,i+1);
		if(zz<n/2)
			dfs(x,xx,y,yy,z+a[3][i],zz+1,i+1);
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll p=1;p<=t;p++){
		maxx=-1;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		dfs(0,0,0,0,0,0,1);
		cout<<maxx<<"\n";
	}
	return 0;
}
