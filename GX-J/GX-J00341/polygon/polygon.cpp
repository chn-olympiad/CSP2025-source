#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10000],flag=1,ans3;
void dfs(long long step,long long sum,long long mx,long long xuan){
	if(step>n){
		if(sum>mx*2 && xuan>=3) ans3++;
		return ;
	}
	dfs(step+1,sum+a[step],max(mx,a[step]),xuan+1);
	dfs(step+1,sum,mx,xuan);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	if(flag){
		long long ans=1,ans1=0;
		for(int i=3;i<=n;i++){
			int tmp=i;
			ans=1;
			for(int j=n;j>=n-i+1;j--){
				ans=ans%998244353*j%998244353;
			}
			for(int j=1;j<=tmp;j++){
				ans=ans%998244353/j%998244353;
			}
			ans1+=ans;
		}
		cout<<ans1;
	}else{
		dfs(1,0,0,0);
		cout<<ans3%998244353;
	}
	return 0;
}
