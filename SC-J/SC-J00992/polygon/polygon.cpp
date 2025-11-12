#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=5e3+5,mod=998244353;
int n,m,a[N];
bool vis[N];
int nw[N],cnt;
lint ans,f[5001*5000];

line void dfs(int u,int sum,int num,int maxl){
	if(num>2 and sum>(maxl<<1)){
		ans=(ans+1)%mod;
	}
	for(int i=u;i<=n;++i){
		dfs(i+1,sum+a[i],num+1,max(maxl,a[i]));
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		m+=a[i];
		if(vis[a[i]]) continue;
		vis[a[i]]=true;
		nw[++cnt]=a[i];
	}
	if(n<=20){
		sort(a+1,a+1+n);
		dfs(1,0,0,0);
		printf("%lld\n",ans%mod);
	}
	else{
		sort(a+1,a+1+n);
		sort(nw+1,nw+1+cnt);
		for(int k=1;k<=cnt;++k){
			for(int i=1;i<=n;++i){
				for(int j=0;j<=m;++j) f[j]=0;
				if(a[i]>nw[k]) break;
				for(int j=m;j>=a[i];--j){
					f[j]=max(f[j],f[j-a[i]]+1)%mod; 
				}
			}
			for(int i=m;i>(nw[k]<<1);--i) ans=(ans+f[i])%mod;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}