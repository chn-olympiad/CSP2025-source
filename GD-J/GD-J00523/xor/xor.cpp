#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const maxn=500000;
int const maxk=2000000;
int n,k;
int a[maxn+1];
int ans;
int lst[maxk+1];
int f[maxk+1];
int qz[maxn+1];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]^a[i];
	}
	for(int i=0;i<=maxk;i++){
		lst[i]=-1;
	}
	lst[0]=0;
	for(int i=1;i<=n;i++){
		int g=qz[i]^k;
		f[i]=max(f[i-1],lst[g]<0?0:f[lst[g]]+1);
		lst[qz[i]]=i;
	}
	printf("%d",f[n]);
	
	return 0;
}
