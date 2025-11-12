#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,N=2e6+10;
int n,k,a[MAXN],f[MAXN],maxx[MAXN],ans,t[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,sum=0;i<=n;i++){
		sum^=a[i];
		if(t[sum^k]) f[i]=maxx[t[sum^k]]+1;
		if(sum==k) f[i]=max(f[i],1);
		maxx[i]=max(maxx[i-1],f[i]),t[sum]=i;
	}
	printf("%d",maxx[n]);
	return 0;
} 

