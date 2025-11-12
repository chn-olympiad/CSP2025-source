#include<bits/stdc++.h>
using namespace std;
struct road{
	long long u,v,w; 
}r[10001];
struct country{
	long long c,a[10001];
}co[10001];
long long n,m,k,dp[10000001][10000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",n,m,k);
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",r[i].u,r[i].v,r[i].w);
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",co[i].c);
		for(int j = 1;j <= n;j++){
         	scanf("%lld",co[i].a[j]);
		}
	}
	if(n==1){
		printf("%d",0);
	}
	return 0;
}
