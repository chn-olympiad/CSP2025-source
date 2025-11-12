#include <stdio.h>
long long m, n, i, j, k, a[500005], b[500005], p, ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[i]=b[i-1]^a[i];
	}
	for(i=1; i<=n; i++){
		for(j=p, k=0; j<i; j++){
			if((b[i]^b[j])==m){
				ans++, k++;
				break;
			}
		}
		if(k){
			p=i;
		}
	}
	printf("%d", ans);
	return 0;
}
