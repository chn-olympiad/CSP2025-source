#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5010];
int ans;
void dfs(int j,int k,int s,int m){
	if(k == n + 1){
		return;
	}
	for(int i = k;i <= n;i++){
		if(s + a[i] > max(m,a[i]) * 2 && j >= 3){
			ans++;
			ans %= mod;
		}
		dfs(j + 1,i + 1,s + a[i],max(m,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}

