#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,c;
long long ans=0;
int a[5000];
void dfs(int k,int h,int xh){
	if(xh>=3 && h>a[k-1]*2){
		ans++;
		ans%=mod;
	}
	if(k>n) return;
	for(int i=k;i<=n;i++){
		dfs(i+1,h+a[i],xh+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 