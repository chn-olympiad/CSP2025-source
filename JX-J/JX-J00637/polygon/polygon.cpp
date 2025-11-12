#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
long long da=0;
int a[5100],b[5100][10];
long long c(int n,int m){
	long long x=1,y=1;
	for(int i=1;i<=n;i++){
		x=x*(m-i+1)%998244353;
		y=y*i%998244353;
	}
	x=x/y%998244353;
	return x;
}
void dfs(int x,long long ans,long long num,long long ns){
	if(x==cnt+1){
		return;
	}
	for(int i=0;i<=b[x][2];i++){
		long long num1=num+i*b[x][1];
		long long ns1=ns+i;
		long long ans1=ans*c(i,b[x][2])%998244353;
		if((num1>2*b[x][1])&&ns1>=3&&i!=0){
			da=(ans1+da)%998244353;
		}
		dfs(x+1,ans1,num1,ns1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			cnt++;
			b[cnt][1]=a[i];
			b[cnt][2]=1;
		}else{
			b[cnt][2]++;
		}
	}
	dfs(1,1,0,0);
	printf("%lld",da);
	return 0;
}
