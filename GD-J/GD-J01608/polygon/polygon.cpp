#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N];
long long ans;
void dfs(int num,int x,int sum){
	if (x==1){
		for (int i=num+1;i<=n;i++){
			if (sum>a[i])ans++;
		}
		ans%=mod;
	}else{
		for (int i=num+1;i<=n;i++){
			dfs(i,x-1,sum+a[i]);
		}
	}
	return ;
}
int solve(int x){
	int sum=1;
	for (int i=n;i>=n-x+1;i--){
		sum*=i;
		sum%=mod;
	}
	for (int i=x;i>=1;i--){
		sum/=x;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n<=3){
		if (n<3)cout<<0;
		else{
			if (a[1]+a[2]>a[3])cout<<1;
			else cout<<0;
		}
	}else if (n<=20){
		for (int i=3;i<=n;i++){
			dfs(0,i,0);
		}
		cout<<ans%mod;
	}else{
		for (int i=3;i<=n;i++){
			ans+=solve(i);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
} 
