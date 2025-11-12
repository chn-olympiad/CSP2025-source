#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long n;
long long a[6500];
long long ans=0;
long long vis[6500]={0};
long long shu[6500];
void dfs(int k,int s) {
	if(k>=3) {
		long long sum=0;
		long long zd=-9999999;
		for(int i=0;i<k;i++){
			sum+=shu[i];
			zd=max(zd,shu[i]) ;
		}
		if(sum>(zd*2)){
			ans++;
		}
	}
	if(k>=n){
		return ;
	}
	for(int i=s;i<=n;i++){
		if(vis[a[i]]!=1){
			shu[k+1]=a[i];
			vis[a[i]]=1;
			dfs(k+1,s+1);
			shu[k+1]=0;
			vis[a[i]]=0;
		}
	}
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];

	}
	dfs(0,1);
	cout<<ans;
	return 0;
}
