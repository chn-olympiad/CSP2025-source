#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],f[5001],ans,flag,c;
void dfs(int sum,int max,int k){
	if(sum>max*2){
		ans++;
		ans%=998244353;
	}
	for(int i=k+1;i<=n;i++){
		if(f[i]==1) continue;
		f[i]=1;
		if(a[i]>max) dfs(sum+a[i],a[i],i);
		else dfs(sum+a[i],max,i);
		f[i]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;ans%=998244353;
		}
		ans-=1;
		ans-=n;
		ans%=998244353;
		c=n*(n-1)/2;
		c%=998244353;
		ans-=c;
		ans%=998244353;
		if(ans>=0){
			cout<<ans;
			return 0;
		}
		else{
			cout<<ans+998244353;
			return 0;
		}
	}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}