#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans,n,a[5009],mx=-1,sum[5009],book[5009];
void dfs(int x,int sum1,int maxn,int k){
	if(x==0){
		if(sum1>2*maxn){
			ans++;
		}
	}
	else{
		for(int i=k;i<=n;i++){
			if(!book[i]){
				book[i]=1;
				dfs(x-1,sum1+a[i],max(maxn,a[i]),i+1);
				book[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,num;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			ans=1;
		}
	}
	else if(mx==1){
		ans=1;
		for(i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		int sum=n*(n+1)/2+1;
		ans=(ans-sum)%mod;
	}
	else{
		for(num=3;num<=n;num++){
			dfs(num,0,0,1);
		}
	}
	printf("%d",ans);
	return 0;
}
