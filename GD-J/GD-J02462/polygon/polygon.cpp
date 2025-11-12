#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5005;
int n,a[N];
int c[N][N];
int read(){
	char d;
	int cnt=0;
	d=getchar();
	while('0'<=d&&d<='9'){
		cnt=cnt*10+d-'0'; 
		d=getchar();
	}
	return cnt;
}
void init(){
	c[0][0]=1;
	c[1][0]=1;
	c[1][1]=1;
	for(int i=2;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
int ans=0;
void dfs(int wz,int sum,int maxn,int geshu){
	if(geshu>=3){
		if(sum>maxn*2){
			ans++;
			ans%=mod;
		}
	}
	for(int i=wz;i<=n;i++){
		dfs(i+1,sum+a[i],max(maxn,a[i]),geshu+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag1=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1){
			flag1=1;
		}
	}
	if(flag1==0){
		init();
		for(int i=3;i<=n;i++){
			ans+=(c[n][i]);
			ans%=mod;
		}
		printf("%d",ans);
		return 0;
	}
	else{
		stable_sort(a+1,a+n+1);
		dfs(1,0,0,0);
		printf("%d",ans);
	}
}
