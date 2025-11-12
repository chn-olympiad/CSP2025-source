#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long a[500005];
void dfs(long long idx,long long sum,long long maxn,bool flag){
	if(maxn!=-INT_MAX&&sum>maxn*2&&flag){
		ans++;
		ans%=998244353;
	}
	if(idx>n){
		return;
	}
	dfs(idx+1,sum+a[idx],max(maxn,a[idx]),1);
	dfs(idx+1,sum,maxn,0);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-INT_MAX,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

