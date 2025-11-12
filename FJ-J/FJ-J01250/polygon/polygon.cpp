#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],ans[5005],cnt;
void dfs(int p,int abc){
	if(p>n){
		if(abc<3){
			return ;
		}
		long long sum=0;
		for(int i=1;i<=abc;i++){
			sum+=ans[i];
		}
		if(ans[abc]*2<sum){
			cnt++;
			cnt%=998244353;
		}
		return ;
	}
	ans[abc+1]=a[p];
	dfs(p+1,abc+1);
	ans[abc+1]=0;
	dfs(p+1,abc);
}
int qpow(int x,int mod){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans<<=1;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-2e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0);
		cout<<cnt%998244353;
	}
	else if(maxn==1){
		cout<<qpow(n-1,998244353);
	}else{
		dfs(1,0);
		cout<<cnt%998244353;
	}
	return 0;
}

