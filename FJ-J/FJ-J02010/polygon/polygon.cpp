#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long ans=1,jian=0;
const long long MOD=998244353;
bool f;
void dfs(int k,int m,int sum){
	if(sum<=a[k]*2&&m>=3) jian++;
	if(sum>a[n]) return;
	for(int i=k+1;i<=n;i++){
		dfs(i,m+1,sum+a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	for(int i=1;i<=n;i++){
		ans=(ans<<1)%MOD;
	}
	ans=ans-n-1-n*(n-1)/2;
	if(f){
		sort(a+1,a+n+1);
		dfs(0,0,0);
	}
	ans-=jian; 
	if(ans<0) while(ans<0) ans+=MOD;
	cout<<ans;
	return 0;
}
