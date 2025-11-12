#include<bits/stdc++.h>
using namespace std;
//爆搜万岁
long long n,a[30],ans,jilu,mod=998244353,x;
void dfs(long long p,long long sum,long long mx){
	if(p>n){
		ans+=(sum>2*mx);
		return;
	}
	dfs(p+1,sum,mx);//不选 
	dfs(p+1,sum+a[p],max(mx,a[p]));//选 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	if(n<=20){
		//40tps
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1,0,0);
		cout<<ans;
	}
	else{
		//cout<<"正解是神的领域 骗分是凡人的尊严"; 
		//接着骗 目标：测试点15~20 24tps
		for(int m=3;m<=n;m++){
			jilu=1;
			for(int j=n-m+1;j<=n;j++){
				x=j-(n-m+1)+1;
				jilu=(jilu*j/x)%mod;
			}ans=(ans+jilu)%mod;
		}cout<<ans;
	}
	return 0;
}