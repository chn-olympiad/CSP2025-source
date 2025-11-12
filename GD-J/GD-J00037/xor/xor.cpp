#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		int p=a[i],t=f[i-1];
		f[i]=f[i-1];
		for(int j=i-1;j>=0;--j){
			if(f[j]!=t) break;
			if(p==k){
				f[i]=f[j]+1;
				break;
			}
			p=int(p^a[j]);
		}
	}
	printf("%d",f[n]);
	return 0;
}
