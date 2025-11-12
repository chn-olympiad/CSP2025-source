#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans=0;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	int now=0, last=1;
	for(int i=1; i<=n; i++){
		now^=a[i];
		if(now==k){
			last=i+1;
			now=0;
			ans++;
			continue;
		}
		int now1=now;
		for(int j=last; j<i; j++){
			now1^=a[j];
			if(now1==k){
				last=i+1;
				now=0;
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
