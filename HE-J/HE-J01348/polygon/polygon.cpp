#include<bits/stdc++.h>
using namespace std;
int n,a[5002];
long long ans,sum;
int dfs(int k,int i,int ma){
	if(k==0) if(sum>ma*2) return 1;
	if(i>n) return 0;
	int r=0;
	sum+=a[i];
	r+=dfs(k-1,i+1,max(ma,a[i]));
	sum-=a[i];
	r+=dfs(k,i+1,ma);
	return r;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int k=3;k<=n;++k) ans=(ans+dfs(k,1,0))%998244353;
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
