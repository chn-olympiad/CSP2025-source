#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],sum;
bool f[5005];
void dfs(int k){
	if(k>n){
		int h=0,maxx=0;
		for(int i=1;i<=n;i++){
			h+=f[i]*a[i];
			maxx=max(maxx,f[i]*a[i]);
		}
		if(h>2*maxx)
			sum=(sum+1)%998244353;
		return;
	}
	dfs(k+1);
	f[k]=1;
	dfs(k+1);
	f[k]=0;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<sum;
	return 0;
}
