#include<bits/stdc++.h>
using namespace std;
int n,tot;
int a[5005];
bool f[5005];
long long ans,tol=1;
void dfs(int gun,int maxa,int cnt,int l){
	if(gun>=3&&cnt>2*maxa) ans=(ans+1)%998244353;
	if(gun==n) return;
	for(int i=l+1;i<=n;i++){
		if(a[i]>maxa) dfs(gun+1,a[i],cnt+a[i],i);
		else dfs(gun+1,a[i],cnt+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) tot++;
	}
	if(n==3){
		if(a[1]>=a[2]+a[3]||a[2]>=a[1]+a[3]||a[3]>=a[2]+a[1]){
			cout<<0;
		}
		else cout<<1;
		return 0;	
	}
	if(tot==n){
		for(int i=3;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				tol=tol*j%998244353;
			}
			ans=(ans+tol)%998244353;
			tol=1;
		}
	}
	else dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
