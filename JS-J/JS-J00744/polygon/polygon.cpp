#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
void dfs(int dep,int sum,int s){
	if(dep>n)return ;
	dfs(dep+1,sum,s);
	if(s>=2&&a[dep]<sum){
		ans++;
		ans%=998244353;
	}
	dfs(dep+1,sum+a[dep],s+1);
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
