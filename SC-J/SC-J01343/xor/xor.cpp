#include<bits/stdc++.h>
using namespace std;
int h[1200001],a[1200001],f[1200001],n,k;
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=(1<<20);i++)h[i]=1e9;
	int res=0;
	h[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		res=res^a[i];
		if(h[res^k]!=1e9){
			f[i]=max(f[h[res^k]]+1,f[i]);
		}
		h[res]=i;
	}
	printf("%d",f[n]);
	return 0;
}
/*
终于有点意思了

大概是注意到在异或的群中每一个元素的逆元是他自己
然后强行使用桶维护一下，发现可以直接dp，于是做完了 

不是这个dev-c++太抽象了，每次一编译就卡，不太舒服，下午可能有点难受了。 
*/