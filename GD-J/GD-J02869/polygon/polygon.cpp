#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 25
#define mod 998244353
int ans=0;
int n;
int a[N];
int aa[N];
void dfs(int k,int m){
	if(k==m+1){
		int sum=0;
		int mx=0;
		for(int i=1;i<=m;i++){
			sum+=a[aa[i]];
			mx=max(mx,a[aa[i]]);
		}
		if(mx*2<sum){
			ans++;
		} 
		ans=ans%mod;
	}
	for(int i=aa[k-1]+1;i<=n;i++){
		aa[k]=i;
		dfs(k+1,m);
		aa[k]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
