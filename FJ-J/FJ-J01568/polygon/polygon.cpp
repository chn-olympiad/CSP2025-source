#include<stdio.h>
#define mod 998244353
int n,a[5001],i;
long long y=1,s;
void dfs(int now,int max,int len){
	if(now>n){
		if(len>(max<<1))++s;
		return;
	}
	dfs(now+1,a[now]>max?a[now]:max,len+a[now]);
	dfs(now+1,max,len);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	if(n<=25)dfs(1,0,0),printf("%d",s%mod);
	else{
		for(i=1;i<=n;++i)y=(y<<1)%mod,++s;
		if(s<3)putchar('0');
		printf("%d",((y-1-s*(s+1)/2)%mod+mod)%mod);
	}
	return 0;
}
