#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,k,a[500005],sum[500005],f[500005],lst[500005],whe[1<<21];
int main(){
//	freopen("a.txt","r",stdin);
//	freopen("c.txt","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	for(int i=1;i<(1<<21);i++) whe[i]=-1;
	for(int i=1;i<=n;i++){
		lst[i]=whe[sum[i]^k];
		whe[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(lst[i]!=-1) f[i]=max(f[i],f[lst[i]]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}
