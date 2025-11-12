#include <bits/stdc++.h>
using namespace std;
int f[1000010];
int maxf[1000010];
int a[1000010];
int main(){
	int n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=-100000;
	for (int i=1;i<=n;i++){
		int sum=0;
		f[i]=-10000000;
		for (int j=i;j>=1;j--){
			sum^=a[j];
			if (sum==k){
				f[i]=maxf[j-1]+1;
				break;
			}
		}
		maxf[i]=max(maxf[i-1],f[i]);
	}
	printf("%d",maxf[n]);
	return 0;
}
