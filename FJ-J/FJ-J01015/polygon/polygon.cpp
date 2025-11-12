#include <bits/stdc++.h>
using namespace std;
const int N=5e3,M=998244353;
int st,n,a[N+5];
bool vst[N+5];
int dfs(int u){
	if(u>n){
		int c1=0,c2=0,t=0;
		for(int i=1;i<=n;i++)
			if(vst[i])
				c1+=a[i],c2++,
				t=max(t,a[i]);
		return c1>t*2 && c2>2;
	}
	vst[u]=1;
	int res=dfs(u+1)%M;
	vst[u]=0;
	return (res+dfs(u+1))%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>1) st=1;
	}
	if(st) printf("%d",dfs(1));
	else printf("%d",(1<<n)%M-n-n*(n-1)/2-1);
	return 0;
}
