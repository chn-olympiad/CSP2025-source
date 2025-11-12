#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long ans;
void dfs(int now,int q,int nsum,int nmax){
	if(now>n){
		if(nsum>nmax*2) ans=(ans+1)%998244353;
		return;
	}
	if(q){
		dfs(now+1,0,nsum+a[now],max(nmax,a[now]));
		dfs(now+1,1,nsum+a[now],max(nmax,a[now]));
		return;
	}
	else{
		dfs(now+1,0,nsum,nmax);
		dfs(now+1,1,nsum,nmax);
		return;
	} 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,0,0,0);
		cout<<ans/2;
	}
	return 0;
}
