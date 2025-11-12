#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,Max=-1,Mod=998244353;
void dfs(long long i,long long m,long long w,long long sum){
	if(w==m){
		if(sum-Max>Max){
			ans++;
			ans%=Mod;
		}
		return;
	}
	if(i==n+1){
		return;
	}
	long long t=Max;
	Max=max(Max,a[i]);
	dfs(i+1,m,w+1,sum+a[i]);
	Max=t;
	dfs(i+1,m,w,sum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		for(long long i=3;i<=n;i++){
			dfs(1,i,0,0);
		Max=-1;
		}
	}
	else{
		long long flag=0;
		for(long long i=1;i<=n;i++){
			if(a[i]!=1){
				flag=1;
				break;
			}
		}
		if(flag==0){
			long long ans=0;
			for(long long i=4;i<=n;i++){
				ans+=n-i+1;
				ans%=Mod;
				for(long long j=i;j<n;j++){
					ans+=(i-1)*n-j;
					ans%=Mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}