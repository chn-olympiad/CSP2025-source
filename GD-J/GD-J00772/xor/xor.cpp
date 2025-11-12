#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,x,u,f[500005],v;
int l[4194310];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	memset(l,-1,sizeof l);
	l[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		u=u^x;
		v=k^u;
		if(l[v]!=-1)f[i]=f[l[v]]+1;
		f[i]=max(f[i],f[i-1]);
		l[u]=i;
	}
	printf("%lld",f[n]);
	return 0;//zrt3
} 
