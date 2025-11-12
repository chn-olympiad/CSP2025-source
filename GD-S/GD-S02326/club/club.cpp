#include<bits/stdc++.h>
using namespace std;
long long n,t,a[114514][3],m[114514],ans;

long long dfs(int x){
	if(x==n) return 0;
	else{
		long long maxn=0;
		for(int i=0;i<3;i++){
			if(m[i]<n/2){
				m[i]++;
				maxn=max( a[x][i]+dfs(x+1),maxn );
				m[i]--;
			}
		}
		return maxn;
	}	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=0;i<n;i++) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		printf("%lld\n",dfs(0));
	}
	return 0;
} 
