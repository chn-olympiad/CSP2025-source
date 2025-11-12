#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,t,s,c,z,ans,a[5005];
int pw(int x,int y){
	int w=1;
	while(y){
		if(y&1) w=w*x%mod,y--;
		x=x*x%mod,y>>=1;
	}
	return w;
}
void dfs(int d){
	if(d>n){
		if(s>2&&c>2*z) ans=(ans+1)%mod;		
		return;
	}
	for(int i=0;i<2;i++){
		int x=z;
		s+=i,c+=i*a[d];
		if(i) z=a[d];
		dfs(d+1);
		s-=i,c-=i*a[d],z=x;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1) t=1;
	}
	if(!t){
		for(int i=3;i<=n;i++){
			s=z=1;
			for(int j=n,k=1;k<=i;j--,k++) s=s*j%mod,z=z*k%mod;
			ans=(ans+s*pw(z,mod-2))%mod;
		}
		return printf("%lld",ans),0;
	}
	sort(a+1,a+1+n),dfs(1);
	return printf("%lld",ans),0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
