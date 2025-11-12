#include <bits/stdc++.h>
using namespace std;

int n,k,ma = 0,a[500001];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		int x = 0,y = 0;
		for(int j = 1;j <= i;j++){
			x ^= a[j];
		}
		for(int j = i + 1;j <= n;j++){
			y ^= a[j];
		}
		if(i == n) if(x == k) ma = max(ma,1);
		else if(x == k && y == k) ma = max(ma,2);
	}
	printf("%d",ma);
}
