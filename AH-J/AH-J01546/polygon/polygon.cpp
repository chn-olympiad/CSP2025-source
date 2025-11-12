#include <bits/stdc++.h>
using namespace std;
const int N =5e5+5;
const int MOD=998244353;
int n;
int a[N];
int ans=0;
void dfs(int x,int maxn,int z,int h){
	if(x>n){
		if(h>maxn*2&&z>2){
			ans++;
		}
		return;
	}
	dfs(x+1,max(maxn,a[x]),z+1,h+a[x]);
	dfs(x+1,maxn,z,h);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(n==3){
		int ans=0,maxn=0;
		for(int i=1; i<=n; i++){
			ans+=a[i];
			maxn=max(a[i],maxn);
		}
		if(ans>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%MOD;
	return 0;
}

