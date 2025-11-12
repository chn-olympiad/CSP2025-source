#include<cstdio>

const int N=5e5+5*5;
int n,k,a[N],b[N],cnt,l=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i]^b[i-1];
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if((b[i]^b[j-1])==k){
				cnt++,l=i+1;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
