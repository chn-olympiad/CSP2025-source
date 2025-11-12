#include<iostream>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=5e3+10;
int n;
ll ans;
int a[N],tol[N];
void dfs(int u,int ii,ll val,int maxx){
	if(u>3){
		if(val>maxx*2){
			ans=(ans+1)%mod;
//			cout<<ans<<" "<<val<<" "<<maxx<<endl;
//			for(int i=1;i<u;i++)cout<<tol[i]<<" ";
//			cout<<endl;
		}
	}
	for(int i=ii;i<=n;i++){
		int max1=max(maxx,a[i]);
		tol[u]=a[i];
		dfs(u+1,i+1,val+1ll*a[i],max1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,1,0,-1);
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/
