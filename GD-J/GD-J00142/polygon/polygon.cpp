#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long Mi(long long x,long long y){
	if(y<0) return 0;
	long long Ans=1;
	while(y){
		if(y&1) Ans=(Ans*x)%Mod;
		x=(x*x)%Mod;
		y>>=1;
	}
	return Ans;
}
int n,a[5005];
long long Tot=0;
/*int Cha(int x){
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(r+l)/2;
		if(a[mid]>=x) r=mid;
		else l=mid;
	}
	return r;
}*/
int dfs(int T,int M,int S){
	if(T>n){
		if(S>2*M) return 1;
		return 0;
	}
	return (dfs(T+1,max(M,a[T]),S+a[T])+dfs(T+1,M,S))%Mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		long long x=n;
		x=((x+1)*x/2)%Mod;
		x=(x+1)%Mod;
		x=(Mi(2,n)-x)%Mod;;
		if(x<0) x+=Mod;
		printf("%lld",x);
		return 0;
	}
	printf("%d",dfs(1,0,0));
	return 0;
}
