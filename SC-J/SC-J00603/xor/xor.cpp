#include<bits/stdc++.h>
using namespace std;
const int M=(1<<21)+5,N=5e5+5;
int n,m,pre[M],sum[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(pre,-1,sizeof(pre));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
	}
	pre[0]=0;
	for(int i=1;i<=n;i++){
		int last=pre[sum[i]^m];
		if(last>=0)
			f[i]=f[last]+1;
		f[i]=max(f[i],f[i-1]);
		pre[sum[i]]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}