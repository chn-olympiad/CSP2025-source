#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],t[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]=a[i]^a[i-1];
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		int x=k^a[i];
		if(t[x]||a[i]==k)
			f[i]=max(f[i],f[t[x]]+1);
		t[a[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}
