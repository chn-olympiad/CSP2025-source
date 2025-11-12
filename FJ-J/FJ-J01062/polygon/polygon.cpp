#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;

int n,a[N],b[N],maxn;
int dfs(int x){
	//o(n*2^n) n<=20
	if(x==n+1){
		int sm=0,ma=0;
		for(int i=1;i<=n;i++) sm+=b[i]*a[i],ma=max(ma,b[i]*a[i]);
		if(sm>2*ma) return 1;else return 0;
	}
	int ans=dfs(x+1);
	b[x]=1;ans+=dfs(x+1);b[x]=0;return ans%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]);
	if(maxn==1) printf("%lld",(long long)(n*(n-1)*(n-2)/6)%mod);
	else printf("%d",dfs(1));
	return 0;
}
//freopen("ploygon.in","w",stidn)
//0001 0000 1010 1001 1111 1100 0111 0000 0000 0100 0010
