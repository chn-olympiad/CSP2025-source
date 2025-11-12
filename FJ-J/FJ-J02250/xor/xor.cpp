#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,k;
int a[N],f[N],lst[M];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=0;i<(1<<20);i++) lst[i]=-1;
	lst[0]=f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(lst[a[i]^k]!=-1) f[i]=max(f[i],f[lst[a[i]^k]]+1);
		lst[a[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}
