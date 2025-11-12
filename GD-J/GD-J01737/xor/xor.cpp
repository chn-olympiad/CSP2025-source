#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N], sum[N], ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout)
	int n, k; scanf("%d", &n, &k);
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		sum[i] = a[i]^sum[i-1];
	}
	int i=1, j=1;
	while (i<=n){
		if (i==j && a[i]==k && i<=n && j<=n){
			ans++;
			i = j+1;
			j = i;
		}else if ((sum[j]^sum[i-1])==k && i<=n && j<=n && sum[j]!=sum[i-1]){
			ans++;
			i = j+1;
			j = i;
		}else j++;
		if (j>n){
			i++;
			j = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
