#include<bits/stdc++.h>
using namespace std;
int sum[500009],f[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		sum[i]=sum[i-1]^t;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==k){
			f[i]=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i+1;
		f[i]=max(f[i],f[i-1]);
		while(j<=n&&(sum[j]^sum[i])!=k) j++;
		if(j<=n) f[j]=max(f[i]+1,f[j]);
	}
	printf("%d",f[n]);
	return 0;
}
