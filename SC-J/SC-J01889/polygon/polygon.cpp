#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mod=998244353,ans;
bool flag=1;
void dfs(int xus,int sum,int ma,int num){
	if(xus>n){
		if(num>=3&&sum>ma*2) ans=(ans+1)%mod;
		return ;
	}
	dfs(xus+1,sum+a[xus],max(ma,a[xus]),num+1);
	dfs(xus+1,sum,ma,num);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1&&flag) flag=0;
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0,0);
		printf("%d",ans);
	}
	else if(flag){
		printf("%d",(int(pow(2,n))-n*(n-1)/2-n-1)%mod);
	}
	return 0;
}