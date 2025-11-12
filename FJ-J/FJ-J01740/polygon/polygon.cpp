#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
bool v[N];
int n,a[N]/*,b[N]*/,ans;
void dfs(int t,int m,/*int b[N]*/int s,int mx,int pre) {
	if(t>m) {
//		int s=0,mx=-10;
//		for(int i=1;i<t;i++) {
//			y+=b[i];
//			mx=max(mx,b[i]);
//		}
		if(s>2*mx) {
			ans=(ans+1)%mod;
//			for(int i=1;i<t;i++) {
//				printf("%d ",b[i]);
//			}printf("\n");
		}
		return;
	}
	for(int i=pre;i<=n;i++) {
		if(!v[i]) {
			/*b[t]=a[i];*/ v[i]=1;
			dfs(t+1,m,/*b*/s+a[i],max(mx,a[i]),i);
			v[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=3;i<=n;i++) {
		for(int i=1;i<=n;i++) v[i]/*=b[i]*/=0;
		dfs(1,i,/*b*/0,-10,1); ans%=mod;
	}
	printf("%d",ans%mod); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
