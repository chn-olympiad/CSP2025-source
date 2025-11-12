#include<bits/stdc++.h>
using namespace std;
long long n,m;
char a[505];
long long b[505],c[505],d[505],e[505];
long long ans;
void dfs(long long x,long long y,long long z){
	if(z>=n){
		if(x>=m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	if(e[n-1]-e[z-1]+x<m) return;
	for(long long i=0;i<n;i++){
		if((y&(1<<i))==0){
			if(z-x>=b[i]){
				dfs(x,y|(1<<i),z+1);
			}
			else if(c[z]==1){
				dfs(x+1,y|(1<<i),z+1);
			}
			else{
				dfs(x,y|(1<<i),z+1);
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='1'){
			c[i]=1;
		}
		e[i]=e[i-1]+c[i];
	}
	for(long long i=0;i<n;i++){
		scanf("%lld",&b[i]);
	}
	for(long long i=0;i<n;i++){
		if(0>=b[i]) dfs(0,1<<i,1);
		else dfs(c[0],1<<i,1);
	}
	printf("%lld",ans);
	return 0;
}
