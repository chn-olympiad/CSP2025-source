#include<bits/stdc++.h>
# define Maxn 500005
# define Maxm 1200005
using namespace std;
int n,k,a[Maxn];
int f[Maxn],g[Maxm];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	memset(g,-1,sizeof(g));
	g[0]=0;
	for(int i=1;i<=n;i++) {
		a[i]^=a[i-1],f[i]=f[i-1];
		if(g[a[i]^k]!=-1)
		f[i]=max(f[i],g[a[i]^k]+1);
		g[a[i]]=max(g[a[i]],f[i]);
	}printf("%d\n",f[n]);
	return 0;
}
