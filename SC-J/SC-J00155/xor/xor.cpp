#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],f[N];
int ls[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int sum=0;
	memset(ls,-1,sizeof(ls));
	ls[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		sum^=a[i];
		if(ls[sum^k]!=-1) f[i]=max(f[i],f[ls[sum^k]]+1);
		ls[sum]=i;
	}
	printf("%d",f[n]);
	return 0;
}