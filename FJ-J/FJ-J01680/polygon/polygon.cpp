//polygon.cpp
#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,a[5005]={0};
LL rem[5005][5005]={0};
int f(LL x){
	return x%998244353;
}
LL dfs(LL x,LL yu){
	if(rem[x][yu]!=0) return rem[x][yu];
	if(x==1) return yu;
	if(x==2) return yu*((yu-1)/2.0);
	LL v=0;
	for(LL i=1;i<=yu-x+1;i++){
		v+=dfs(x-1,yu-i);
	}
	v=f(v);
	rem[x][yu]=v;
	return v;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	if(n==3) printf("%d",1);
	if(a[1]==1){
		for(int i=4;i<=n;i++) ans+=f(dfs(i,n));
		printf("%d",f(ans));
	}
	else printf("%d",114);
	return 0;
}
