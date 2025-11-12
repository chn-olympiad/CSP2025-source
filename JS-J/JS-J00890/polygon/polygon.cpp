#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[50001],s[50001];
long long ans;
void dfs(int maxn,int n,int sum,int dep){
	if(s[dep-1]+sum<=maxn*2) return ;
	if(n>=3 && sum>maxn*2) ans++;
	int i=dep-1;
	while(s[i]+sum>=maxn*2 && i>0){
		dfs(maxn,n+1,sum+a[i],i);
		i--;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=1;i<=n-2;i++) ans+=i;
		cout<<ans%mod;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=n;i>=3;i--) dfs(a[i],1,a[i],i);
	cout<<ans%mod;
	return 0;
}
