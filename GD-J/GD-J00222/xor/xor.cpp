#include<cstdio>

int n,k,a[500004];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int num=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]) num++;
	}
	if(k) printf("%d",num);
	else printf("%d",num/2);
	return 0;
}
