#include<bits/stdc++.h>
using namespace std;
long long n,maxn,ans,a[5010];
void dfs(long long he,long long ma,long long shang,long long c,long long dc){
	if(c==dc+1){
		if(he>ma*2) ans++;
		return;
	}
	if(shang==n) return;
	for(long long i=shang+1;i<=n;i++){
		dfs(he+a[i],max(ma,a[i]),i,c+1,dc);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(maxn==1){
		cout<<((((n-1)*(n-2))%998244353)/2)%998244353;
		return 0;
	}
	else if(n==3){
		if((a[1]+a[2]+a[3])>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		ans=0;
		for(long long j=3;j<=n;j++){
			dfs(0,0,0,1,j);
		}
		cout<<ans%998244353;
	}
	return 0;
}
