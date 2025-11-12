#include<bits/stdc++.h>		
using namespace std;
const int mode=998244353;
long long n,a[10000],dp[10000],ans;
void dfs(int sum,int cnt,int m){
	if(sum>a[cnt]) ans++; 
	for(int i=m+1;i<cnt;i++){
		dfs(sum+a[i],cnt,i);
	}
}long long sum(int n,int m){
	int x=1,y=1,z=1;
	for(int i=1;i<=n;i++) x*=i;
	for(int i=1;i<=m;i++) y*=i;
	for(int i=1;i<=m-n;i++) z*=i;
	return y/x/z;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(a[1]==1&&a[n]==1){
		for(int i=3;i<=n;i++){
			ans+=sum(i,n);
			ans%=mode;
		}cout<<ans;
		return 0;
	}
	for(int i=1;i<=3;i++){
		dfs(0,i,0);
	}cout<<ans%mode;
}
 
