#include<stdio.h>
int n,k,a[500002],ans;
bool vis[500002],f;
int main() {
	freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int k=0; k<n; k++)
		for(int i=1; i<=n-k; i++) {
			f=0;
			for(int l=i; l<=i+k; l++) {
				if(vis[l]) {
					f=1;
					break;
				}
			}
			if(f)break;
			int x=0;
			for(int b=i; b<=i+k; b++) {
				x^=a[b];
			}
			if(x==k) {
				ans++;
				for(int b=i; b<=i+k; b++)vis[b]=1;
			}
		}
	printf("%d",ans);
	return 0;
}
