#include <iostream>
#include <cstdio>
using namespace std;

int n,k,ans,a[501000];
long long qz;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) {
		qz = 0;
		for (int j = i;j <= n;j++) {
			qz ^= a[j];
			if (qz == k) {
				ans++;
				i = j;
				break;
			}
		}
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
