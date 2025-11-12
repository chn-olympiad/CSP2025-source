#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[5010],ans;
void dfs(int cur,int cnt,int sum){
	ans%=998244353;
	if(cnt>=3 && a[cur]*2<sum) ans++; 
	for(int i=cur+1;i<=n;i++){
		dfs(i,cnt+1,sum+a[i]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}

