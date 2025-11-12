#include<bits/stdc++.h>
using namespace std;
long long a[5005],n; 
long long ans,x=993244353;
inline void dfs(long long k,long long sum,long long maxx,long long m,long long last){
	if(k==n+2){
		return;
	}
	if(m>=3&&sum>maxx*2&&last){
		ans++;
		ans=ans%x;
	}
	dfs(k+1,sum+a[k],max(maxx,a[k]),m+1,1);
	dfs(k+1,sum,maxx,m,0);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
