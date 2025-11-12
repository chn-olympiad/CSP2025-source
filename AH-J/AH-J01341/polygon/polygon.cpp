/*AK CSP-J*/
#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],d[5005],s1,k,w,ans,rans,x[5005],f[5005],sum,maxn;
void dfs(long long s){
	for(int i=1;i<s;i++){
		 if(x[i-1]>=x[i])return ;
	}
	for(int i=1;i<s;i++){
		 sum+=a[x[i]];
		 maxn=max(maxn,a[x[i]]);
	}
	if(maxn*2<sum)ans++;
	sum=0,maxn=0;
	if(s==n+1)return ;
	for(int i=s;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			x[s]=i;
			dfs(s+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
5
2 2 3 8 10
*/
