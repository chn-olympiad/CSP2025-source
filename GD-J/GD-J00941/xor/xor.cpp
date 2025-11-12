#include<bits/stdc++.h>
using namespace std;
int n, k, a[500003], b[500003], l = 1, sum;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	b[1] = a[1];
	for(int i = 2; i <= n; i++){
		b[i] = a[i] ^ b[i - 1];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == k){
			sum++;
			l = i + 1;
		}else{
			for(int j = l; j < i; j++){
				int s = (b[i] ^ b[j - 1]);
				if(s == k){
					sum++;
					l = i + 1;		
					break;
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
