#include <bits/stdc++.h>
using namespace std;
long long a[1000006];
long long n;
long long ans[105][1000005]; 
long long dfs(long long now,long long maxx,long long sum2){
	
	long long ans2=0;
	if(sum2>maxx*2){
		ans2++;
	}
	if(now==n)return ans2;
	if(ans[now][sum2])return ans[now][sum2];
	for(int i=now+1;i<=n;i++){
			ans2=(ans2+dfs(i,a[i],sum2+a[i]))%998244353;
	}
	ans[now][sum2]=ans2%998244353;
	return ans2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		cout<<(n*(n-1))%998244353*(n-2)/6%998244353;
		return 0;
	}
	if(n==3){
		long long ans3=a[1]+a[2]+a[3];
		if(ans3>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<dfs(0,0,0);
	return 0;
}
